#include "Queue.hpp"
#include "Stack.hpp"

#include <iostream>

int main(){
    // test Stack and Queue data structures
    Stack* S1 = new Stack();
    Queue* Q1 = new Queue();

    // create abc string
    string abc_string[] = {"a", "b", "c", "d", "e", "f", "g",
        "h", "i", "j", "k", "l", "m", "n",
        "o", "p", "q", "r", "s", "t", "u",
        "v", "w", "x", "y", "z"};

    // test empty function
    if (S1->isEmpty())
    {
        cout << "isEmpty() test passed-> Stack S1->isEmpty(): " << 
        (S1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed-> Stack S1->isEmpty(): " <<
        ( S1->isEmpty() == true ? "true" : "false" ) << endl;
    }

    if (Q1->isEmpty())
    {
        cout << "isEmpty() test passed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }

    // create two test linked lists
    for (string it : abc_string)
    {
        // test insertHead function
        cout << "Q1: " << endl;
        Q1->add(it);        // insert node at the head of linked list
        Q1->printQueue(); // print current linked list

        // test insertTail function
        cout << "S1: " << endl;
        S1->push(it); // insert node at tail of linked list
        S1->printStack();
    }

    // test empty function
    if (S1->isEmpty())
    {
        cout << "isEmpty() test failed-> Stack S1->isEmpty(): " << 
        (S1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test passed-> Stack S1->isEmpty(): " <<
        ( S1->isEmpty() == true ? "true" : "false" ) << endl;
    }

    if (Q1->isEmpty())
    {
        cout << "isEmpty() test failed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test passed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }

    // test removal functions

    // while stack is not empty
    while(!S1->isEmpty()){
        string cData = S1->pop();
        cout << "Removed " << cData << ", from S1 Stack->" << endl;
        cout << "S1: " << endl;
        S1->printStack();
    }

    // while quque is not empty
    while(!Q1->isEmpty()){
        string cData = Q1->remove(); 
        cout << "Removed " << cData << ", from Q1 Queue->" << endl;
        cout << "Q1: " << endl;
        Q1->printQueue();
    }

    // test isEmpty function
    if (S1->isEmpty())
    {
        cout << "isEmpty() test passed-> Stack S1->isEmpty(): " << 
        (S1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed-> Stack S1->isEmpty(): " <<
        ( S1->isEmpty() == true ? "true" : "false" ) << endl;
    }

    if (Q1->isEmpty())
    {
        cout << "isEmpty() test passed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }
    else
    {
        cout << "isEmpty() test failed-> Queue Q1->isEmpty(): " << 
        (Q1->isEmpty() == true ? "true" : "false") << endl;
    }

    delete S1;
    delete Q1;

    // return 0 on successful execution
    return 0;
}