#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Node
{
    string data;
    struct node *next;
    int position;
};

class SingleLinkedList
{
    struct node
    {
        string data;
        node *next;
    };

    node *head = NULL;

public:
    void insertNodeEnd(string data);
    void insertNodeBegin(string data);
    void display();
    void deleteNodeByValue(string key);
    void deleteHead();
    void deleteTail();
    void deleteAtPosition(int position);
    void addPosNode(string data, int pos);
    void reverselist();
    void findDuplicate();
    void sortLinkedList();
};

class DoublyLinkedList
{
    struct Node
    {
        int data;
        struct Node *prev;
        struct Node *next;
    };
    struct Node *head = NULL;
    static int count;

public:
    void display();

    // where the current head is present
    void insertAtStart(int newData);

    // where the first node is present with next=Null
    void insertAtEnd(int newData);

    // at a particular position
    void insertAtPostion(int newData, int position);

    void deleteNode(int position);
};

class CircularList
{
public:
    int count;
    struct node
    {
        int data;
        node *next;
    };
    struct node *head, *head2, *prev;

    CircularList();
    void insertAtEnd(int newData);
    void insertAtStart(int newData);
    void insertAtPosition();
    void deleteNode();
    void display();
    void breakLinkedList();
};

class Stack
{
    float *arr;
    int size;

public:
    int top;
    Stack()
    {
        size = 10;
        arr = new float[size];
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(int num);
    float pop();
};

class Queue
{
private:
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue(int s);
    void insert(int j);
    int remove();
    int peek();
    bool isEmpty();
    bool isFull();
    int Size();
    void display();
};

class maxHeap
{
public:
    void swap(int *a, int *b);
    void heapify(vector<int> &hT, int i);
    void insert(vector<int> &hT, int newNum);
    int peekMax(const vector<int> &hT);

    //  Extract function to get and remove the maximum value (for a max-heap)
    int extractMax(vector<int> &hT);

    void deleteNode(vector<int> &hT, int num);
    void printArray(vector<int> &hT);
};

class minHeap
{
public:
    void swap(int *a, int *b);
    void heapify(vector<int> &hT, int i);
    void insert(vector<int> &hT, int newNum);
    int peekMin(const vector<int> &hT);

    // Extract function to get and remove the minimum value (for a min-heap)
    int extractMin(vector<int> &hT);
    void deleteNode(vector<int> &hT, int num);
    void printArray(vector<int> &hT);
};
#endif