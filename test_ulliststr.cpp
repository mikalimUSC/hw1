#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{


  ULListStr list;

   cout<< " List size starts at " << list.size() <<endl;



   list.push_front("a");
   list.push_front("b");
    list.push_front("c");
      list.push_front("d");
    list.push_front("e");
   // [    b a ]
   cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
  cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
  cout << " Starting to POP front."<< endl;
  list.pop_front();
  list.pop_front();
  list.pop_front();

   cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;

    
    //visualize: [a,b,c,d,e,f,g,h,i,j] -> [k]

    // cout << " Before popping back. list size is " << list.size() << endl;
    // list.pop_back();
    //  cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // list.pop_back();
    // cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
    // list.pop_back();
    // cout<< " List size now " << list.size() <<endl;
    // cout << " front is " << list.front()<< " back is "<< list.back()<<endl;

}





