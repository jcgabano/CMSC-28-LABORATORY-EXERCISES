/*Name external header file for activity 2*/

#include <iostream>
#include <string>
using namespace std;

class Name{
  private:
    string fname;
    string lname;

  public:
    Name(){}

  void setfname(string newfname){
    fname = newfname;
  }

  string getfname(){
    return fname;
  }

  void setlname(string newlname){
    lname = newlname;
  }

  string getlname(){
    return lname;
  }
};