# Text Editor
A basic text editor made from the implementation of DSAA and C++

# TABLE OF CONTENTS:
1.	About the project
2.	What is DSA implementation in it?
3.	Functionalities this program performs
# >Insert
# >Delete
# >	Copy
# > Paste
# >	Highlight
# >	Search
# >	Undo
# >	Redo
# >	Filing
# >Display
4.	Most challenging part 
5.	Advantages 
6.	Limitations
7.	Conclusion
8.	Output screenshots

 
# 	 ABOUT THE PROJECT:
Creating a user-friendly text editor with a simple interface, efficient text manipulation, and seamless file handling, inspired by the ease-of-use and basic functionality of Notepad.
# 	WHAT IS IMPLEMMENTATION OF DSA IN IT?:
# >Linked List:
 Using a linked list in a text editor allows for dynamic and efficient handling of text data. As users insert, delete, or modify words in the editor, linked lists provide a flexible structure for managing the sequence of words. This dynamic structure avoids the need to allocate a fixed amount of memory, enabling the editor to handle varying lengths of text. 
# >Stack:
 A stack is beneficial for implementing undo and redo functionalities in a text editor. Each operation, such as inserting or deleting a word, can be pushed onto the stack. This allows for easy reversal of operations through undo, as the last operation can be popped off the stack and reversed. Similarly, redo functionality involves pushing undone operations back onto the stack.
Both linked lists and stacks contribute to an efficient, scalable, and easily maintainable structure for managing text data and user operations in a text editor.

# 	FUNCTIONALITIES THIS SYSTEM ENABLES TO PERFORM:
This Text Editor is a simple and lightweight application designed for basic text editing tasks. It focuses on providing a clean and straightforward user interface without the advanced features found in more sophisticated code editors or word processors. 
With the help of this system, one can be facilitated from the following operations:
  FUNCTIONS FOR USER:
# >	Main:
The main function will be giving user the options to select to perform the suitable tasks. We have used the switch structure to take the choice from the user and switch to the above-shown cases. While the user doesn’t choose to exit this program will go on.

# >	Insert:
The Insert function enables users to input text at their discretion. Our program utilizes a linked list, treating each word as a node.
This function takes input as a string until ‘-1’ is entered. Then it will check for words by checking the spaces and inserts it in node of linked list by calling  createNode() function.
# >	Delete:
Delete permits users to remove any chosen word from the inputted text based on its position in the linked list.
This function takes position as input and checks it with each node’s data’s position. If the position matches the node’s data then it links the next node with the previous node and deletes the current node.
# >	Copy:
Copy function duplicates a word from the inputted text.
This function takes word as input and checks it with each node’s data. If word matches then it copies it in a variable which is then use to paste.

# >	Paste:
Paste inserts the copied word at any specified position within the user-entered text.
This function takes position of word as input and checks it with each node’s data.At that position it creates new node and place it in existing linked list.

# >	Highlight:
Highlight emphasizes a word at the position indicated by the user.
This function takes position as input and checks it with each node’s data’s position. If word matches with node’s data then it places ‘[‘ before and ‘]’ after word to make it highlight.

# >	Search Word:
Search Word locates a specific word in the text and provides information on its occurrences.
This function takes word as input and checks it with each node’s data.It counts occurrence of that word in entire text with respect to their positions.

# >	Undo:
Undo allows the program to save each word's position and operation in a stack, facilitating the reversal of the latest change.
It basically stores each operation and word on which operation is applied in a stack. When undo is called it pops the uppermost operations and undo the changes applied on the text.

# >	Redo:
Redo preserves the text stored in Undo before its reversal, ensuring the tracking of both the latest and oldest changes.
Every undo word is stored in another stack for redo. When redo is called it pops the uppermost operation and revert the undone change.

# >	Filing:
Filing saves the most recent text display, including any modifications, into a file.
Write function takes text from display everytime change is made and writes it in a file. It splits lines by the word count of words in a line at time of input.
Read function reads text from the file and prints it on the display terminal.

# >	Display:
The Display function showcases the current state of the text, presenting the contents of the linked list. This feature provides users with a visual representation of the entered text, including any modifications made through other functionalities. It enhances user interaction by offering a comprehensive view of the ongoing text editing process.

 Important Point:
After each functionality, the main function will be called to display the choices to enter until the choice “0” will be chosen. In that condition, the program will exit.
Also header file of class containing different data structures is added for reusability and efficiency of code.

# MOST CHALLENGING PART:
The hardest aspect was putting in as much validation as we could. We initially found it challenging, but we eventually succeeded since using validations was essential for DSA implementation to be perfect; otherwise, our code would have not been complete. Another challenging part was to keep track of every change made in the text for undo and redo purposes. The final issue was storing words in nodes as our text contained spaces that were not part of words. With group efforts, we overcome all the hurdles making our project implementable.

# 	ADVANTAGES:
	 Our program uses both linked lists and stacks that can contribute to an efficient, scalable, and easily maintainable structure for managing text data and user operations in the text editor.
 
   Our program is entirely focused on the goal of the course i.e. implementation of Data Structure Algorithms and Applications.

# 	LIMITATIONS:

-	It is terminal-based and highly menu-driven which may cause users a slight inconvenience.
-	It lacks advanced features like line shift, words or character counts, colored highlighting, and may have some more.

# 	CONCLUSION:
The Text Editor Project aims to develop a user-friendly and efficient text editor, drawing inspiration from the simplicity of Notepad. It utilizes linked lists for dynamic text manipulation and incorporates stacks for undo and redo capabilities. The editor facilitates seamless insertion, deletion, and modification of text, providing adaptability to different text lengths.
