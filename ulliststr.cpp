#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{


  return size_;
}

// WRITE YOUR CODE HERE



void ULListStr::push_back(const std::string& val){
  if(tail_==nullptr){ //empty list
    Item* item = new Item();
    item->val[0] = val;
    item->first = 0; 
    item->last = 1;
    head_ = item;
    tail_ = item;
    size_++;
    return;
  }
  if(tail_->last != ARRSIZE){ //Case: Tail still has space
    tail_->val[tail_->last] = val;
    tail_->last++;


  }else{ //Gotta add a whole new item node

    Item* item = new Item();
    item->first=0;
    item->last = 1;
    tail_->next = item;
    item->prev = tail_;
    tail_ = item;
    tail_->val[tail_->first] = val;
     
  }
  size_++;
  }


  void ULListStr::pop_back(){

    if(size_!=0 && tail_!=nullptr){
  
      if(tail_->last - tail_->first==1){
        if(tail_!=head_){
          Item* temp = tail_;
          tail_->prev->next = nullptr; 
          tail_ = tail_->prev; 
          tail_->last = ARRSIZE;
          delete temp; 
        }else{
  
          delete tail_;
          head_ = nullptr;
          tail_ = nullptr;
        }
      }else{
   
        tail_->last--;
      }
    size_--;
  
    }

  }

    void ULListStr::push_front(const std::string& val){

      if(head_==nullptr){ //empty list
      Item* item = new Item();
      item->val[0] = val;
      item->first = 0; 
      item->last = 1;
      head_ = item;
      tail_ = item;
      size_++;
      return;
      }

    if(head_->first != 0){ //Case: dont have to add a whole new node
      head_->val[head_->first-1] = val;
      head_->first--;
    }else{
      
      Item* item = new Item();
      item->first=ARRSIZE-1;
      item->last = ARRSIZE;
      head_->prev = item;
      item->next = head_;
      head_ = item;
      head_->val[head_->first] = val;
    }
    size_++;

    }

   void ULListStr::pop_front() {
    if (size_ != 0 && head_ != nullptr) {
        if (head_->last - head_->first == 1) {
            if (head_ != tail_) {
                Item* temp = head_;
                head_->next->prev = nullptr; 
                head_ = head_->next; 
                head_->first = 0;
          
                delete temp; 
            } else {
                delete head_;
                head_ = nullptr;
                tail_ = nullptr;
            }
        } else {
            head_->first++;
        }
        size_--;
    }
}

  std::string const & ULListStr::back() const{
    if(size_==0){
    
      return "";
    }
    
    return tail_->val[tail_->last-1];

  }
 std::string const & ULListStr::front() const {
  if(size_ ==0){
      return "";
    }

    return head_->val[head_->first];
 }


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

  std::string*  ULListStr::getValAtLoc(size_t loc) const{
    if (loc >= size_) {
        return nullptr;
    }

    Item* current = head_;
    while (current != nullptr) {
        for (int i = current->first; i < current->last; i++) {
            if (loc == 0) {
                return &(current->val[i]);
            }
            --loc;
        }
        current = current->next;
    }

    return nullptr;
    
  }

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
