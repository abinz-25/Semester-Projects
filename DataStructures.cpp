#include "dataStructures.h"

SingleLinkedList::~SingleLinkedList()
{
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
SingleLinkedList::insertNodeEnd(string data)

{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}
void SingleLinkedList::insertNodeBegin(string data)
{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void SingleLinkedList::display()
{
    cout << endl
         << "----------------" << endl;
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "-";
        cout << ptr->next << endl;
        ptr = ptr->next;
    }
    cout << "----------------" << endl;
}

void SingleLinkedList::deleteNodeByValue(string key)
{
    node *temp = head;
    node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void SingleLinkedList::deleteHead()
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
}

void SingleLinkedList::deleteTail()
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    delete temp;
}

void SingleLinkedList::deleteAtPosition(int position)
{
    if (head == NULL || position <= 0)
    {
        return;
    }
    else if (position == 1)
    {
        deleteHead();
        return;
    }
    else
    {
        node *temp = head;
        node *next_node;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
    }
}
void SingleLinkedList::addPosNode(string data, int pos)
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
            new_node->next = head;
            head = new_node;
        }
        else
        {
            node *temp = head;
            int i = 1;
            while (i < pos - 1 && temp != NULL)
            {
                temp = temp->next;
                i++;
            }

            if (temp == NULL)
            {
                cout << "Position out of bounds." << endl;
                return;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void SingleLinkedList::reverselist()
{
    struct node *prev = NULL;
    struct node *nextptr = NULL;
    while (head != NULL)
    {

        nextptr = head->next;
        head->next = prev;
        prev = head;
        head = nextptr;
    }
    head = prev;
    cout << endl
         << "Printing list in reverse order: " << endl;
    display();
}

void SingleLinkedList::findDuplicate()
{
    int num = 0;
    struct node *ptr = head;
    struct node *ptr2 = ptr->next;

    while (ptr->next != NULL)
    {
        while (ptr2 != NULL)
        {
            if (ptr->data == ptr2->data)
            {
                num++;
            }
            ptr2 = ptr2->next;
        }
        if (num > 0)
        {
            cout << endl
                 << "->" << ptr->data;
            num = 0;
        }
        ptr = ptr->next;
        ptr2 = ptr->next;
    }
}
void SingleLinkedList::sortLinkedList()
{
    struct node *i, *j;
    int temp;
    i = head;
    while (i->next != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void DoublyLinkedList::display()
{
    struct Node *ptr;
    ptr = head;
    cout << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
void DoublyLinkedList::insertAtStart(int newData)
{

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newData;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
    count++;
    cout << endl
         << "After inserting at end" << endl;
    display();
}
void DoublyLinkedList::insertAtEnd(int newData)
{
    Node *newnode = new Node;
    newnode->data = newData;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        // If the list is empty, make the new node the head
        head = newnode;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Add the new node at the end
        current->next = newnode;
        newnode->prev = current;
        count++;
    }
    cout << endl
         << "After inserting at start" << endl;
    display();
}
void DoublyLinkedList::insertAtPostion(int newData, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position" << endl;
    }
    Node *newnode = new Node;
    newnode->data = newData;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (position == 1)
    {
        insertAtStart(newData);
    }
    else
    {
        Node *temp = head;
        int i = 1;
        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            cout << "Position out of bounds." << endl;
            return;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
        count++;
        cout << endl
             << "After inserting at position" << endl;
        display();
    }
}

void DoublyLinkedList::deleteNode(int position)
{

    Node *temp = head;

    if (position <= 0 || head == NULL || position > count)
    {
        cout << "Invalid position" << endl;
    }
    if (position == 1)
    {
        head = head->next;

        delete temp;
    }
    else
    {
        Node *next_node;
        int i = 1;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        next_node = temp->next;
        temp->next->prev = next_node->prev;      // connecting after->prev  with prev one
        next_node->prev->next = next_node->next; // connectign prev->next to after
        delete next_node;
    }
    count--;
    cout << endl
         << "After deleting node" << endl;
    display();
}

CircularList::CircularList()
{
    head = NULL;
    head2 = NULL;
    prev = NULL;
    count = 0;
}
void CircularList::insertAtEnd(int newData)
{
    count++;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = head;
    if (head == NULL)
    {
        head = newNode;
        prev = head;
        return;
    }
    prev->next = newNode;
    prev = newNode;
}
void CircularList::insertAtStart(int newData)
{
    count++;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
}
void CircularList::insertAtPosition()
{
    count++;
    int pos, newData;
    cout << endl
         << "Enter the data you want to insert in the list: ";
    cin >> newData;
    cout << endl
         << "Enter the position: ";
    cin >> pos;
    if (pos == 1)
    {
        insertAtStart(newData);
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    struct node *ptr = head;
    int i = 1;
    while (i < pos - 1 && ptr->next != head)
    {
        ptr = ptr->next;
        i++;
    }
    if (i < pos - 1)
    {
        cout << endl
             << "Out of bound index.";
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
void CircularList::deleteNode()
{
    count--;
    int pos;
    cout << endl
         << "Enter the position of node you want to delete: ";
    cin >> pos;
    if (pos == 1)
    {
        struct node *temp = head;
        head = head->next;
        prev->next = head;
        free(temp);
        return;
    }
    struct node *ptr = head;
    int i = 1;
    while (i < pos - 1 && ptr->next != head)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr->next == head)
    {
        cout << endl
             << "Index out of bound.";
        return;
    }
    struct node *nextNode = ptr->next;
    ptr->next = nextNode->next;
    free(nextNode);
}
void CircularList::display()
{
    struct node *ptr = head;
    cout << endl
         << "List 1:" << endl;
    do
    {
        cout << ptr->data << " - " << ptr->next << endl;
        ptr = ptr->next;
    } while (ptr != head);
    if (head2 == NULL)
        return;
    ptr = head2;
    cout << endl
         << "List 2:" << endl;
    do
    {
        cout << ptr->data << " - " << ptr->next << endl;
        ptr = ptr->next;
    } while (ptr != head2);
}
void CircularList::breakLinkedList()
{
    int i = 1;
    struct node *ptr = head;
    if (count % 2 != 0)
    {
        cout << endl
             << "!! List can not be broken into perfect halves due to odd number of elements!!";
    }
    while (i < count / 2)
    {
        ptr = ptr->next;
        i++;
    }
    head2 = ptr->next;
    ptr->next = head;
    struct node *temp = head2;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head2;
    cout << endl
         << "After breaking into half:";
    display();
}

Stack::Stack()
{
    size = 10;
    arr = new float[size];
    top = -1;
}
bool Stack::isEmpty()
{
    return (top == -1);
}
bool Stack::isFull()
{
    return (top == size - 1);
}
void Stack::push(int num)
{
    arr[++top] = num;
}
float Stack::pop()
{
    if (isEmpty())
    {
        cout << endl
             << "Stack is empty.";
        exit(0);
    }
    float val = arr[top--];
    return val;
}
Queue::Queue(int s) : size(s)
{
    array = new int[size];
    front = -1;
    rear = -1;
}
void Queue::insert(int j)
{
    if (!isFull())
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            array[rear] = j;
        }
        else
        {
            rear = (rear + 1) % size;
            array[rear] = j;
        }
    }
}
int Queue::remove()
{
    if (!isEmpty())
    {
        if (front == rear)
        {
            int deletedValue = array[front];
            cout << "The deleted value at position  " << front << " is " << deletedValue << endl;
            front = rear = -1;
            return deletedValue;
        }
        else
        {
            cout << "Deleted value at position  " << front << " is " << array[front] << endl;
            front = (front + 1) % size;
        }
    }
    else
    {
        cout << "queue is empty so no element can be removed" << endl;
        return -1; // Return a default value or handle it appropriately
    }
}
int Queue::peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "no element present in queue" << endl;
        return -1;
    }
    else
    {
        return array[front];
    }
}
bool Queue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Queue::Size()
{
    return size;
}
void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty to be displayed.";
        return;
    }
    else if (front < rear || front == rear)
    {
        for (int i = front; i <= rear; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = front; i <= size - 1; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

void maxHeap::swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void maxHeap::heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;
    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void maxHeap::insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    hT.push_back(newNum);

    int i = size; // Index of the newly inserted element

    while (i > 0 && hT[i] > hT[(i - 1) / 2])
    {
        swap(&hT[i], &hT[(i - 1) / 2]); // element is swapped with its parent as long as it is greater.
        i = (i - 1) / 2;
    }
}

int maxHeap::peekMax(const vector<int> &hT)
{
    if (!hT.empty())
    {
        return hT[0];
    }
    else
    {
        cerr << "Heap is empty." << endl;
        return 0; // Assuming integer values
    }
}
//  Extract function to get and remove the maximum value (for a max-heap)
int maxHeap::extractMax(vector<int> &hT)
{
    if (!hT.empty())
    {
        int maxValue = hT[0];
        swap(&hT[0], &hT[hT.size() - 1]);
        hT.pop_back();
        heapify(hT, 0);
        return maxValue;
    }
    else
    {
        cerr << "Heap is empty." << endl;
        return 0; // Assuming integer values
    }
}
void maxHeap::deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);
    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(hT, i);
}
void maxHeap::printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

void minHeap::swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void minHeap::heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && hT[l] < hT[smallest])
        smallest = l;

    if (r < size && hT[r] < hT[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&hT[i], &hT[smallest]);
        heapify(hT, smallest);
    }
}

void minHeap::insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    hT.push_back(newNum);

    int i = size; // Index of the newly inserted element

    while (i > 0 && hT[i] < hT[(i - 1) / 2])
    {
        swap(&hT[i], &hT[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int minHeap::peekMin(const vector<int> &hT)
{
    if (!hT.empty())
    {
        return hT[0];
    }
    else
    {
        cerr << "Heap is empty." << endl;
        return 0; // Assuming integer values
    }
}

// Extract function to get and remove the minimum value (for a min-heap)
int minHeap::extractMin(vector<int> &hT)
{
    if (!hT.empty())
    {
        int minValue = hT[0];
        swap(&hT[0], &hT[hT.size() - 1]);
        hT.pop_back();
        heapify(hT, 0);
        return minValue;
    }
    else
    {
        cerr << "Heap is empty." << endl;
        return 0; // Assuming integer values
    }
}

void minHeap::deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;

    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }

    swap(&hT[i], &hT[size - 1]);
    hT.pop_back();

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(hT, i);
}

void minHeap::printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";

    cout << "\n";
}