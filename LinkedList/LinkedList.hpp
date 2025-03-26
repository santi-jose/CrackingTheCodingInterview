#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <string>

using namespace std;

// node class
class Node
{
private:
    Node *next = nullptr;
    Node *prev = nullptr;
    string data = "";

public:
    // constructor
    Node(string data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    // getters
    string getData() { return data; }
    Node *getNext() { return next; }
    Node *getPrev() { return prev; }

    // setters
    void setData(string newData) { data = newData; }
    void setNext(Node *nextNode) { next = nextNode; }
    void setPrev(Node *prevNode) { prev = prevNode; }
};

// linkedlist class
class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList();
    ~LinkedList();

    // insert functions
    void insertHead(string data);
    void insertTail(string data);

    // remove functions
    string removeHead();
    string removeTail();

    // empty checker
    bool isEmpty();

    // print function
    void printLinkedList(bool forward=true);
};

#endif
