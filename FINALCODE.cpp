#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "TEXT_EDITOR.h"
using namespace std;
void setConsoleColor(WORD color)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, color);
}

int main()
{
	system("color 70");
	int pos;
	int choice;
	string word;
	TEXT_EDITOR T;
again1:
again:
	cout << endl
		 << "\t\t\t                  ______________________" << endl;
	cout << endl
		 << "\t\t\t              *   WELCOME TO TEXT EDITOR    * " << endl;
	cout << "\t\t\t                  ______________________" << endl;

	while (true)
	{

		cout << endl
			 << "\t\t\t----------------------------------------------------------------" << endl;
		cout << "\t\t\t1. Enter Text      2. Delete Word        3. Copy Word " << endl;
		cout << "\t\t\t4. Paste Word      5. Highlight Word     6. Undo" << endl;
		cout << "\t\t\t7. Redo            8. Display Text    9. Read file " << endl;
		cout << "\t\t\t0. Exit" << endl;
		cout << "\t\t\t-----------------------------------------------------------------" << endl;
		cout << "\n\t\t\t______________________" << endl;

		cout << endl
			 << "  Enter choice: ";
		if (cin >> choice)
		{
			switch (choice)
			{
			case 1:
				cout << endl
					 << "|| Please Enter -1 to stop input ||" << endl
					 << endl;

				T.insert();
				goto again;
				break;
			case 2:
			c2:
				cout << "  Which word do you want to delete?" << endl;
				cin >> word;
				T.search_word(word);
				cout << "  Enter position to delete: ";
				if (cin >> pos)
				{
					T.deleteAtPosition(pos);
					goto again;
				}
				else
				{
					exceptionHandling();
					goto c2;
				}
				break;
			case 3:
				cout << "  Which word you want to copy: ";
				cin >> word;
				T.copy(word);
				goto again;
				break;
			case 4:
			c4:
				cout << "  At what position you want to paste the word? ";
				if (cin >> pos)
				{
					T.paste(pos);
					goto again;
				}
				else
				{
					exceptionHandling();
					goto c4;
				}
				break;
			case 5:
			c5:
				cout << "  Which word do you want to highlight?" << endl;
				cin >> word;
				T.search_word(word);
				cout
					<< "  Enter position for highlight: ";
				if (cin >> pos)
				{
					T.highlightWord(pos);
					goto again;
				}
				else
				{
					exceptionHandling();
					goto c5;
				}
				break;
			case 6:
				cout << "  Undoing last operation..." << endl;
				T.undo();
				goto again;
				break;
			case 7:
				cout << "  Redoing last undone operation..." << endl;
				T.redo();
				goto again;
				break;
			case 8:
				T.display();
				goto again;
				break;
			case 9:
				T.ReadFile();
				goto again;
				break;
			case 0:
				cout << "Exit." << endl;
				return 0;
			default:
				cout << "  Invalid choice. Please enter a valid option." << endl;
				goto again1;
				break;
			}
		}
		else
		{
			exceptionHandling();
			goto again1;
		}

		return 0;
	}
}