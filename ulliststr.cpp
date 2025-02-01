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
    head_ = tail_ = item;
  }
  if(tail_->last != ARRSIZE-1){ //Case: Tail still has space
    tail_->val[tail_->last] = val;
    tail_->last++;

  }else{ //Gotta add a whole new item node

    tail_->val[tail_->last] = val;
    Item* item = new Item();
    item->prev = tail_;
    item->next = nullptr;
    item->first =0;
    item->last = 1;
    tail_->next = item;
    tail_ = item;
     

  }
  size_++;
  }


  void ULListStr::pop_back(){
    if(size_==0){
      return;
    }
    if(tail_->last-1==0){
      Item* temp = tail_->prev;
      delete tail_;
      tail_ = temp;
      tail_->next = nullptr;
      return;
      
    }else{
            tail_->val[tail_->last-1] = nullptr;
    tail_->last--;
    }
     if (head_->first == head_->last && head_ == tail_) { 
        clear(); 
    }


    size_--;
  }

    void ULListStr::push_front(const std::string& val){

    }

    void ULListStr::pop_front(){

    }

  std::string const & ULListStr::back() const{
    if(size_==0){
      return nullptr;
    }
    return tail_->val[tail_->last-1];

  }

 std::string const & ULListStr::front() const {
  if(size_==0){
      return nullptr;
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
