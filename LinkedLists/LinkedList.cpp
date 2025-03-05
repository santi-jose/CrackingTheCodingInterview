#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"

using namespace std;

// constructor
LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

// destructor
LinkedList::~LinkedList()
{
    // iterate through LinkedList
    Node *cur = this->head;
    while (cur != nullptr)
    {
        Node *deleteNode = cur; // store node to delete into temporary
        cur = cur->getNext();   // move cursor to next node
        delete (deleteNode);    // delete the current node
    }
}

// insertion functions

// insert node at head of linked list
void LinkedList::insertHead(string data)
{
    Node *newNode = new Node(data);
    if (this->isEmpty())
    { // if the linkedlist is empty
        // set the head and tail Node pointers
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {                               // linkedlist is not empty, the head is not a nullptr
        Node *oldHead = this->head; // store old head in a temp variable
        newNode->setNext(oldHead);  // set the new node next to old head
        oldHead->setPrev(newNode);  // set the old head previous to new node
        this->head = newNode;       // set head to new node
    }
    this->length++; // increment linked list length variable
}

// insert node at tail of linked list
void LinkedList::insertTail(string data)
{
    Node *newNode = new Node(data); // create new node using input data
    if (this->isEmpty())
    { // if the linkedlist is empty
        // set the tail and head node pointers
        this->tail = newNode;
        this->head = newNode;
    }
    else
    {
        Node *oldTail = this->tail; // store old tail in temp variable
        newNode->setPrev(oldTail);  // set new node prev to old tail
        oldTail->setNext(newNode);  // set old tail next to new node
        this->tail = newNode;       // set tail to new node
    }
    this->length++; // increment lnked list length variable
}

// removal functions
string LinkedList::removeHead()
{
    // if the linked list is not empty
    if (!(this->isEmpty()))
    {
        // if the length of the linkedlist is 1
        if (this->length == 1)
        {
            Node* oldHead = this->head; // store node to delete
            string returnData = oldHead->getData(); // store data to return
            this->head = nullptr; // set head to nullptr
            this->tail = nullptr; // set tail to nullptr
            delete(oldHead); // delete node to remove from linkedlist
            this->length--; // decrement length
            return returnData; // return node data
        }
        else // length of linkedlist > 1
        {
            // temp variables
            Node *oldHead = this->head;             // store old head in temp var
            Node *newHead = oldHead->getNext();     // store new head in temp var
            string returnData = oldHead->getData(); // store data to return

            // reassign new head pointers
            this->head = newHead;      // set head of linkedlist to new head
            newHead->setPrev(nullptr); // set prev of new head to nullptr

            delete (oldHead); // delete old head
            this->length--;   // decrement the length of the linkedlist variable
            return returnData;
        }
    }else{ // print error message
        cout << "Cannot remove head of empty linked list!" << endl;
        return "";
    }
}

string LinkedList::removeTail()
{
    // if our linkedlist is not empty
    if(!(this->isEmpty())){
        if(this->length == 1){ // if length of linkedlist is 1
            Node* oldTail = this->tail; // store node to delete
            string returnData = oldTail->getData(); // store data to return
            this->tail = nullptr; // set tail to nullptr
            this->head = nullptr; // set head to nullptr
            delete(oldTail); // delete node to remove from linkedlist
            this->length--; // decrement length
            return returnData; // return data
        }else{ // length > 1
            // temp variables
            Node* oldTail = this->tail; // old tail temp var
            Node* newTail = oldTail->getPrev(); // new tail temp var
            string returnData = oldTail->getData(); // return data temp var

            //reassign new tail pointers
            this->tail = newTail;
            newTail->setNext(nullptr);

            delete(oldTail);
            this->length--;
            return returnData;
        }
    }else{ // print error message
        cout << "Cannot remove tail of empty linked list!" << endl;
        return "";
    }
}

// empty check
bool LinkedList::isEmpty()
{
    if (this->length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// print function
void LinkedList::printLinkedList(bool forward)
{
    if (forward)
    { // print forward
        // iterate through linkedlist front to back
        Node *cur = this->head;
        while (cur != nullptr)
        {
            cout << "[" << cur->getData() << "]"; // print current node
            cur = cur->getNext();                 // move cursor to next node in linkedlist
            if (cur != nullptr)
            {                 // if the cursor does not point to nullptr
                cout << "->"; // print pointer to next node
            }
        }
    }
    else
    { // print backward
        // iterate through linkedlist back to front
        Node *cur = this->tail;
        while (cur != nullptr)
        {
            cout << "[" << cur->getData() << "]"; // print current node
            cur = cur->getPrev();                 // move cursor to prev node in linkedlist
            if (cur != nullptr)
            {                 // if the cursor does not point to nullptr
                cout << "->"; // print pointer to next node
            }
        }
    }
}
