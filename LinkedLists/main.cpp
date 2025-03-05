#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main(void)
{
    // create test linked list of alphabet
    LinkedList *test1 = new (LinkedList);

    string abc_string[] = {"a", "b", "c", "d", "e", "f", "g",
                           "h", "i", "j", "k", "l", "m", "n",
                           "o", "p", "q", "r", "s", "t", "u",
                           "v", "w", "x", "y", "z"};

    for(string it: abc_string){
        test1->insertHead(it); // insert node at the head of linked list
        test1->printLinkedList(); // print current linked list
    }

    return 0;
}