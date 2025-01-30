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
using namespace std;

/* Add a prototype for a helper function here if you need */
void splithelp(Node*& node, Node*& odds, Node*& evens);
Node* odds = nullptr;
Node* evens = nullptr;
Node* add(Node*& list, Node*& node);

void split(Node*& in, Node*& odds, Node*& evens)
{
  odds = nullptr;
  evens = nullptr;
  splithelp(in,odds,evens);
  delete in;
}



/* If you needed a helper function, write it here */

void splithelp(Node*& node, Node*& odds, Node*& evens)
{
  if(node == nullptr){
    return;
  }
 
  if(node->value %2 ==0){
    evens = add(evens,node);
    
  }else{
    odds = add(odds,node);
  }

  Node* next = node->next;

  splithelp(next,odds,evens);


}

Node* add(Node*& list, Node*& node){
  if(node == nullptr){
    return list;
  }

  if(list == nullptr ){
     Node* newNode = new Node(node->value,nullptr);
    list = newNode;

    return list;
  }
  if(list->next == nullptr){
    
    Node* newNode = new Node(node->value,nullptr);
    
    list->next = newNode;
    return list;
  }

  add(list->next,node);
  return list;

}

