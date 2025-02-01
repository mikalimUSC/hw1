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
   list.push_back("a");
   list.push_back("b");
   list.push_back("c");
  cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
  list.push_back("d");
   list.push_back("e");
   list.push_back("f");
   list.push_back("g");
   list.push_back("h");
   list.push_back("i");
   list.push_back("j");
    list.push_back("k");
    list.pop_back();
    cout<< " List size now " << list.size() << " front is " << list.front()<< " back is "<< list.back()<<endl;
}

