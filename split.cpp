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

void split(Node*& in, Node*& odds, Node*& evens)
{
  odds = nullptr;
  evens = nullptr;

  splithelp(in,odds,evens);
  in = nullptr;
}

/* If you needed a helper function, write it here */

void splithelp(Node*& node, Node*& odds, Node*& evens)
{
  cout<< "splithelp: node is " << node->value<<endl;
 
  if(node == nullptr){
    return;
  }
  Node*next = nullptr;
  if(node->next !=nullptr){
    cout<< " Node-> next not equal to nullptr , val is " << node->next->value<<endl;
     next = node->next;
  }

  if(node->value %2 ==0){
     cout<< "Adding" << node ->value << " to evens"<<endl;
    evens = add(evens,node);
    
  }else{
    cout<< "Adding" << node ->value << " to odds"<<endl;
    odds = add(odds,node);
    


  }


  if(next !=nullptr){
  splithelp(next,odds,evens);
  }



}

Node* add(Node*& list, Node*& node){
 
  if(node == nullptr){
    return list;
  }

  if(list == nullptr ){
      cout << "add: node value is " << node->value<< " list  is null"<< endl;
    //  Node* newNode = new Node(node->value,nullptr);
    list = node;
    node->next = nullptr;
    return list;
  }

  
  if(list->next == nullptr){
    cout << "add: node value is " << node->value<< " list is " << list->value << " also listnext null"<< endl;
    // Node* newNode = new Node(node->value,nullptr);
   
    list->next = node;
    node->next = nullptr;
    return list;
  }

  cout << "add: node value is " << node->value<< " list is " << list->value<< endl;
  add(list->next,node);
 
  return list;

}