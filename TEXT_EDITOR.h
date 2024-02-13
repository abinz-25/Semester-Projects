#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include "DataStructures.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
class TEXT_EDITOR
{
    string copyWord;
    struct node
    {
        string data;
        struct node *next;
        int position;
    };
    struct Stack
    {
        int position;
        string data, operation;
        struct Stack *next;
    };
    int disCount[100];
    int nodecount;
    struct node *head;
    struct Stack *UndoStack;
    struct Stack *RedoStack;
    bool undovar;

public:
    TEXT_EDITOR()
    {
        nodecount = 0;
        head = NULL;
        UndoStack = RedoStack = NULL;
        undovar = false;
        copyWord = "";
        for (int i = 0; i < 100; ++i)
        {
            disCount[i] = 0;
        }
    }
    // after inserting and deleting the position of remaining nodes is changed.
    void restorePosition(struct node *N, string s)
    {
        N = N->next;
        if (s == "delete")
        {
            while (N != NULL)
            {
                N->position--;
                N = N->next;
            }
        }
        else if (s == "insert")
        {
            while (N != NULL)
            {
                N->position++;
                N = N->next;
            }
        }
    }
    // every element is inserted in the UndoStack with its operation after being inserted, deleted, highlighted or pasted.
    void saveUndo(struct node *N, string op)
    {
        struct Stack *newElement = new Stack;
        newElement->data = N->data;
        newElement->operation = op;
        newElement->position = N->position;
        newElement->next = UndoStack;
        UndoStack = newElement;
    }
    // same like insertion at end.
    void push(string data)
    {
        struct node *new_node = new struct node;
        new_node->data = data;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            new_node->position = 1;
            nodecount++;
        }
        else
        {
            struct node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = new_node;
            if (new_node->data == "" || new_node->data == " ")
            {
                new_node->position = 0;
                return;
            }
            new_node->position = nodecount + 1;
            nodecount++;
        }
        saveUndo(new_node, "insert");
    }
    void ReadFile()
    {
        struct node *ptr = NULL;
        ifstream infile("Text.txt");

        if (infile.is_open())
        {
            cout << endl
                 << "File opened successfully" << endl;
            // if file is empty
            if (infile.peek() == ifstream::traits_type::eof())
            {
                cout << "File is empty." << endl;
            }
            else
            {
                // Read data from the file
                string word;
                while (getline(infile, word))
                {
                    cout << word << endl;
                }
                cout
                    << endl
                    << "Data has been read from the file." << endl;

                // Close the file
                infile.close();
            }
        }
        else
        {
            cerr << "Failed to open the file for reading." << endl;
        }
    }
    void writeToTextFile(node *head)
    {
        // Remove the file if it exists
        remove("Text.txt");

        // Open the file for writing
        ofstream writefile("Text.txt");

        // Check if the file is successfully opened
        if (writefile.is_open())
        {
            // cout << endl
            // 	 << "File opened successfully" << endl;
            node *temp = head;
            // Write data from the linked list to the file
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < disCount[i]; j++)
                {
                    if (temp != NULL)
                    {
                        writefile << temp->data << " ";
                        temp = temp->next;
                    }
                }
                if (temp == NULL)
                {
                    break;
                }
                if (disCount[i] > 0)
                    writefile << endl;
            }
            // Close the file
            writefile.close();

            cout << endl
                 << endl
                 << "| Data has been saved to the file. |" << endl;
        }
        else
        {
            cerr << "Failed to open the file for writing." << endl;
        }
    }

    void display()
    {
        struct node *ptr = head;
        cout << endl
             << "  ----------------- " << endl;
        cout << "  Current text is : " << endl;
        cout << "  ----------------- " << endl;
        cout << "  ";
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < disCount[i]; j++)
            {
                if (ptr != NULL) // Check if ptr is not null before accessing
                {
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
            }
            if (ptr == NULL)
            {
                break;
            }
            if (disCount[i] > 0) // Only move to the next line if elements were displayed
                cout << endl
                     << "  ";
        }
        writeToTextFile(head);
        cout << endl;
        // Add an extra newline to separate the Current text section
    }

    void deleteHead()
    {
        if (head == NULL)
        {
            return;
        }
        struct node *temp = head;
        restorePosition(temp, "delete");
        head = head->next;
        delete temp;
    }

    void addPosNode(string data, int pos)
    {
        if (head == NULL || pos <= 0)
        {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        else
        {
            node *new_node = new node();
            new_node->data = data;
            new_node->next = NULL;

            if (pos == 1)
            {
                new_node->position = 1;
                new_node->next = head;
                head = new_node;
                saveUndo(new_node, "insert");
                restorePosition(new_node, "insert");
                disCount[0]++;
                nodecount++;
            }
            else
            {
                node *temp = head;
                // every node has a position so instead of taking i it is checked on the basis of position.
                // node having position zero represents extra spacing within text. e.g. "you {   } are programming."
                while ((temp->position < pos - 1 || temp->position == 0) && temp != NULL)
                {
                    temp = temp->next;
                }

                if (temp == NULL)
                {
                    cout << "Position out of bounds." << endl;
                    return;
                }

                new_node->next = temp->next;
                new_node->position = pos;
                temp->next = new_node;
                saveUndo(new_node, "insert");
                restorePosition(new_node, "insert");
                int sum = disCount[0], i = 0;
                while (1)
                {
                    if (sum >= pos)
                    {
                        if (undovar == true)
                        {
                            undovar = false;
                            break;
                        }
                        disCount[i]++;
                        break;
                    }
                    else
                    {
                        sum += disCount[i + 1];
                        i++;
                    }
                }
                nodecount++;
            }
        }
    }

    void deleteAtPosition(int position)
    {
        if (head == NULL || position <= 0 || position > nodecount)
        {
            cout << "  Invalid position or list is empty." << endl;
            return;
        }
        else if (position == 1)
        {
            saveUndo(head, "delete");
            deleteHead();
            disCount[0]--;
            nodecount--;
        }
        else
        {
            struct node *temp = head;
            struct node *nextNode;
            while ((temp->position < position - 1 || temp->position == 0) && temp != NULL)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << endl
                     << "  There is no word at this position to delete.";
                return;
            }

            while (temp->next->data == "" || temp->next->data == " ")
                temp = temp->next;
            cout << endl
                 << "  Deleted word: '" << temp->next->data << "'" << endl;
            nextNode = temp->next;
            temp->next = nextNode->next;
            saveUndo(nextNode, "delete");
            restorePosition(nextNode, "delete");
            delete nextNode;
            int sum = disCount[0], i = 0;
            while (1)
            {
                if (sum >= position)
                {
                    disCount[i]--;
                    break;
                }
                else
                {
                    sum += disCount[i + 1];
                    i++;
                }
            }
            nodecount--;
        }

        display();
    }

    void highlightWord(int position)
    {

        string word;
        node *temp = head;

        if (position <= 0)
        {
            cout << "  Invalid position" << endl;
        }
        else
        {
            while (temp->position <= position - 1 && temp != NULL)
            {
                temp = temp->next;
            }

            if (temp == NULL)
            {
                cout << "  Position out of bounds." << endl;
                return;
            }
            if (temp->data[0] == '[' && temp->data[temp->data.length() - 1] == ']')
            {
                cout << endl
                     << "Already highlighted.";
                display();
                return;
            }
            word = "[";
            word += temp->data;
            word += "]";
            temp->data = word;
            saveUndo(temp, "highlight");
            display();
        }
    }

    void undo()
    {
        if (UndoStack == NULL)
        {
            cout << "Nothing to undo." << endl;
            return;
        }

        struct Stack *undoData = UndoStack;
        UndoStack = UndoStack->next;
        // in undo inverse operation is performed for every node in the undo stack.
        if (undoData->operation == "delete")
        {
            int sum = disCount[0], i = 0;
            while (i < 10)
            {
                if (sum == undoData->position - 1)
                {
                    disCount[i]++;
                    undovar = true;
                    break;
                }
                else
                {
                    sum += disCount[i + 1];
                    i++;
                }
            }
            addPosNode(undoData->data, undoData->position);
            cout << endl
                 << "Undone: Inserting '" << undoData->data << "' at position " << undoData->position << endl;
        }
        else if (undoData->operation == "insert")
        {
            deleteAtPosition(undoData->position);
            cout << endl
                 << "Undone: Deleting word at position " << undoData->position << endl;
        }
        else if (undoData->operation == "highlight")
        {
            // Extract the original word without brackets
            string originalWord = undoData->data.substr(1, undoData->data.length() - 2);

            // Replace the highlighted word with the original word
            node *temp = head;
            int i = 1;
            while (i < undoData->position && temp != NULL)
            {
                temp = temp->next;
                i++;
            }

            if (temp != NULL)
            {
                saveUndo(temp, "highlight");
                temp->data = originalWord;
                cout << endl
                     << "Undone: Remove Highlighting at position " << undoData->position << endl;
                display();
            }
            else
            {
                cout << "Invalid position for undoing highlight operation." << endl;
            }
        }

        // Push the undone operation to RedoStack
        undoData->next = RedoStack;
        RedoStack = undoData;
        UndoStack = UndoStack->next;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void redo()
    {
        if (RedoStack == NULL)
        {
            cout << "Nothing to redo." << endl;
            return;
        }

        struct Stack *redoData = RedoStack;
        RedoStack = RedoStack->next;

        if (redoData->operation == "delete")
        {
            cout << endl
                 << "Redone: Deleting word at position " << redoData->position << endl;
            deleteAtPosition(redoData->position);
        }
        else if (redoData->operation == "insert")
        {
            int sum = disCount[0], i = 0;
            while (i < 10)
            {
                if (sum == redoData->position - 1)
                {
                    disCount[i]++;
                    undovar = true;
                    break;
                }
                else
                {
                    sum += disCount[i + 1];
                    i++;
                }
            }
            cout << endl
                 << "Redone: Inserting '" << redoData->data << "' at position " << redoData->position << endl;
            addPosNode(redoData->data, redoData->position);
        }
        else if (redoData->operation == "highlight")
        {
            cout << endl
                 << "Redone: Highlighting '" << redoData->data << " at position " << redoData->position << endl;
            highlightWord(redoData->position);
        }

        // Push the redone operation to UndoStack
        redoData->next = UndoStack;
        UndoStack = redoData;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void copy(string word)
    {
        struct node *temp = head;
        if (temp == NULL)
        {
            cout << endl
                 << "No text to copy.";
            return;
        }
        else if (temp->next == NULL)
        {
            if (temp->data == word)
            {
                copyWord = word;
                cout << endl
                     << "Word copied successfully" << endl;
            }
            else
            {
                cout << endl
                     << "NO word matched to be copied.";
                return;
            }
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->data == word)
                {
                    copyWord = word;
                    cout << endl
                         << "'" << copyWord << "' copied!";
                    break;
                }
                temp = temp->next;
            }
        }
        if (temp == NULL)
            cout << endl
                 << "NO word matched to be copied.";
    }

    void paste(int position)
    {
        struct node *temp = head;

        if (head == NULL || position < 0)
        {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        else
        {
            struct node *new_node = new node;
            new_node->data = copyWord;
            new_node->next = NULL;

            if (position == 1)
            {
                // Insert at the beginning of the text
                new_node->next = head;
                head = new_node;
                new_node->position = 1;
                saveUndo(new_node, "insert");
                restorePosition(new_node, "insert");
                disCount[0]++;
                nodecount++;
            }
            else
            {
                // Traverse to the node at the specified position
                while (temp != NULL && temp->position != position - 1)
                {
                    temp = temp->next;
                }

                if (temp == NULL)
                {
                    cout << "Invalid position. Please enter a valid number." << endl;
                    return;
                }

                new_node->next = temp->next;
                temp->next = new_node;
                new_node->position = position;
                saveUndo(new_node, "insert");
                restorePosition(new_node, "insert");
                int sum = disCount[0], i = 0;
                while (1)
                {
                    if (sum + 1 >= position)
                    {
                        disCount[i]++;
                        break;
                    }
                    else
                    {
                        sum += disCount[i + 1];
                        i++;
                    }
                }
                nodecount++;
            }
        }
        display();
    }

    void insert()
    {
        string word = "";
        string c;
        int j = 0;
        while (disCount[j] != 0)
        {
            cout << endl
                 << disCount[j];
            j++;
        }
        cout << "  Enter Text: " << endl;
        cout << "----------------" << endl;
        for (int v = j - 1; v < 100; v++)
        {
            // for taking one line and terminate on pressing enter.
            cout << " ";
            getline(cin, c);
            if (c == "-1")
            {

                break;
            }

            for (int i = 0; i < c.length(); i++)
            {

                if (c[i] != ' ')
                {
                    word += c[i];
                }
                else
                {
                    if (!word.empty())
                    {
                        push(word);
                        disCount[v]++;
                        word = "";
                    }
                }
            }
            // Push the last word in the line
            if (!word.empty())
            {
                push(word);
                disCount[v]++;
                word = "";
                cout << " ";
            }
        }
        display();
    }
    void search_word(string word)
    {
        int occurrence_count = 0;
        struct node *temp = head;

        if (temp == NULL)
        {
            cout << endl
                 << "No text to search." << endl;
            return;
        }

        while (temp != NULL)
        {
            if (temp->data == word)
            {
                occurrence_count++;
                if (occurrence_count == 1)
                {
                    cout << "Word: '" << word << "' found at" << endl
                         << "position:  " << temp->position;
                }
                else
                {
                    cout << endl
                         << "position " << temp->position;
                }
            }
            temp = temp->next;
        }

        if (occurrence_count > 0)
        {
            if (occurrence_count == 1)
                cout << endl;
            else
                cout << endl
                     << "'"
                     << word << "' occured " << occurrence_count << " time(s) in the text." << endl
                     << endl;
        }
        else
        {
            cout << "No occurrence of '" << word << "' found in the text." << endl;
        }
    }
};
void exceptionHandling()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    cout << "Invalid entry. Please enter a valid input." << endl;
}
#endif