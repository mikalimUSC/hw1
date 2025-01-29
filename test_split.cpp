/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
int main(int argc, char* argv[])
{


//List is [1,2,4,3]
Node* four =new  Node(3,nullptr);
Node* three = new Node(4,four);
Node* two = new Node(2, three);
Node* one = new Node(1,two);

//verify i set up this list correctly LOL

 Node* current = one;
// while(current != nullptr){
//     std::cout << current->value << std::endl;
//     current = current->next;
// }
Node* odds = nullptr;
Node* evens = nullptr;
Node* nullInput = nullptr;

split(nullInput,odds, evens);
void delete_list(Node*& head)

std::cout << "odds:" << std::endl;
current = odds;
while(current != nullptr){
    std::cout << current->value << std::endl;
    current = current->next;
}

std::cout << "evens:" << std::endl;
current = evens;
while(current != nullptr){
    std::cout << current->value << std::endl;
    current = current->next;
}
  delete_list(odds);
    delete_list(evens);
    delete_list(one);
}

void delete_list(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}