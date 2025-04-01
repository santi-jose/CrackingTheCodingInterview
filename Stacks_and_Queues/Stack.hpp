#ifndef STACK_HPP
#define STACK_HPP

#include "../LinkedList/LinkedList.hpp" // Reference LinkedList header

class Stack{
    private:
        LinkedList* list; // list to store for stack

    public:
        Stack(); // Stack constructor
        ~Stack(); // stack destructor
        string pop(); // remove the top item from the stack
        void push(string data); // add an item to the top of the stack
        string peek(); // return the data at the top of the stack
        bool isEmpty(); // return true if and only if the stack is empty
        void printStack(); // print the stack top to bottom
};

#endif