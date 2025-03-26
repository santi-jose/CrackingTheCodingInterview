#include "Stack.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

string Stack::pop(){
    // remove the top of the stack
    // and return the value at the top of the stack
    return this->list->removeHead(); 
}

void Stack::push(string data){
    // push new node with input string data
    // onto top of stack
    this->list->insertHead(data);
}

string Stack::peek(){
    // return value at the top of the stack
    return this->list->returnHData();
}

bool Stack::isEmpty(){
    // check if the stack is empty
    return this->list->isEmpty();
}

void Stack::printStack(){
    this->list->printLinkedList();
}