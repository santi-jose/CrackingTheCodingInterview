#include "Queue.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

Queue::Queue(){
    this->list = new LinkedList();
}

Queue::~Queue(){
    delete this->list;
}

void Queue::add(string data){
    // add node with input string data at end of queue
    this->list->insertTail(data);
}

string Queue::remove(){
    // remove the node at the front of the list
    // and return the data stored in that node
    return this->list->removeHead();
}

string Queue::peek(){
    // return the data string stored at node in the front of the list
    return this->list->returnHData();
}

bool Queue::isEmpty(){
    // check if queue is empty
    return this->list->isEmpty();
}

void Queue::printQueue(){
    // print the list from front t oback
    this->list->printLinkedList();
}