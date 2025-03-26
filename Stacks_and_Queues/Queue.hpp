#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../LinkedList/LinkedList.hpp" // Reference LinkedList header

class Queue{
    private:
        LinkedList* list; // list to store for queue

    public:
        void add(string data); // Add an item to the end of the list
        string remove(); // remove the first item in the list
        string peek(); // peek at the value at the front of the list
        bool isEmpty(); // return true if an d only i the queue is empty
        void printQueue(); // print the Queue front -> back
};

#endif