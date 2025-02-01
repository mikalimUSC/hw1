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
  cout << " Val is " << val << endl;
  if(tail_==nullptr){ //empty list
    Item* item = new Item();
    item->val[0] = val;
    item->first = 0; 
    item->last = 1;
    head_ = item;
    tail_ = item;
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
  
      cout << " tail->last is " << tail_->last << " tail first is " << tail_->first<<endl;
      if(tail_->last - tail_->first==1){
        if(tail_!=head_){
          cout << "Tail not equal to head but we are about to delete a whole item" << endl;
          Item* temp = tail_;
          tail_->prev->next = nullptr; 
          tail_ = tail_->prev; 
          tail_->last = ARRSIZE;
          delete temp; 
        }else{
          cout << " k"<<endl;
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

    }

    void ULListStr::pop_front(){

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
