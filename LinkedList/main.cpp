#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main(void)
{
    // create test linked list of alphabet
    LinkedList *test1 = new LinkedList();
    LinkedList *test2 = new LinkedList();

    string abc_string[] = {"a", "b", "c", "d", "e", "f", "g",
                           "h", "i", "j", "k", "l", "m", "n",
                           "o", "p", "q", "r", "s", "t", "u",
                           "v", "w", "x", "y", "z"};

    // test empty function
    if (test1->isEmpty())
    {
        cout << "isEmpty() test passed. LinkedList test1->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed. LinkedList test1->isEmpty(): " <<
        ( test1->isEmpty() == true ? "true" : "false" ) << endl;
    }

    if (test2->isEmpty())
    {
        cout << "isEmpty() test passed. LinkedList test2->isEmpty(): " << 
        (test2->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed. LinkedList test2->isEmpty(): " << 
        (test2->isEmpty() == true ? "true" : "false") << endl;
    }

    // create two test linked lists
    for (string it : abc_string)
    {
        // test insertHead function
        cout << "test1: " << endl;
        test1->insertHead(it);        // insert node at the head of linked list
        test1->printLinkedList(true); // print current linked list

        // test insertTail function
        cout << "test2: " << endl;
        test2->insertTail(it); // insert node at tail of linked list
        test2->printLinkedList(true);
    }

    // test empty function
    if (test1->isEmpty())
    {
        cout << "isEmpty() test failed. LinkedList test1->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test passed. LinkedList test1->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }

    if (test2->isEmpty())
    {
        cout << "isEmpty() test failed. LinkedList test2->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test passed. LinkedList test2->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }

    // test removal function

    // while our test1 LinkedList is not empty
    while (!test1->isEmpty())
    {
        string cData = test1->removeTail();
        cout << "Removed " << cData << ", from test1 LinkedList." << endl;
        cout << "test1: " << endl;
        test1->printLinkedList();
    }

    // while our test2 linkedList is not empty
    while (!test2->isEmpty())
    {
        string cData = test2->removeHead();
        cout << "Removed " << cData << ", from test2 LinkedList." << endl;
        cout << "test2: " << endl;
        test2->printLinkedList();
    }

    // test isEmpty function
    // test empty function
    if (test1->isEmpty())
    {
        cout << "isEmpty() test passed. LinkedList test1->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed. LinkedList test1->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }

    if (test2->isEmpty())
    {
        cout << "isEmpty() test passed. LinkedList test2->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed. LinkedList test2->isEmpty(): " << 
        (test1->isEmpty() == true ? "true" : "false") << endl;
    }

    delete test1;
    delete test2;

    return 0;
}