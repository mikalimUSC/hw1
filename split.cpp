/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */
void splithelp(Node*& node, Node*& odds, Node*& evens);
Node* odds = nullptr;
Node* evens = nullptr;
Node* add(Node*& list, Node*& node);
void print_list(Node* list);

void split(Node*& in, Node*& odds, Node*& evens)
{
  splithelp(in,odds,evens);
}



/* If you needed a helper function, write it here */

void splithelp(Node*& node, Node*& odds, Node*& evens)
{
  
  if(node == nullptr){
    std::cout << " node is null"<<std::endl;
    return;
  }
  std::cout << "splithelp:current value is " << node->value<< std::endl;
  if(node->value %2 ==0){
    evens = add(evens,node);
    cout<< "splithelp: added " << node->value<<" to evens"<<endl;
    print_list(evens);
    
  }else{
    odds = add(odds,node);
    cout<< "splithelp: added " << node->value<<" to odds"<<endl;
    print_list(odds);
  }

cout << "verifying value of node is still " << node->value<<endl;
  Node* next = node->next;

  // std::cout << "running with next node w/ val" << next->value<< std::endl;
    
  splithelp(next,odds,evens);


}

Node* add(Node*& list, Node*& node){
  if(node == nullptr){
    return list;
  }
  if(list ==nullptr){
    Node* newNode = new Node(node->value,nullptr);
    list = newNode;
    return list ;
  }

  Node* current = list;
  // cout<< "add:current value is "<< current->value<<endl;
  // cout<<"node value is " << node->value<<endl;

  if(current->next !=nullptr){
    while(current->next != nullptr){
    current = current->next;
    }
  }
//cout<< "passed while loop. val of current is " << current->value <<endl;
  Node* newNode = new Node(node->value,nullptr);
  current->next = newNode;
  //cout <<"leaving add after adding"<<endl;
  return list;
 
}

void print_list(Node* list){
  cout<<" [";
  Node* current =list;
  while(current != nullptr){
    cout<< current->value;
    current=current->next;
    cout << " , ";
  }
  cout<<"]"<<endl;
}