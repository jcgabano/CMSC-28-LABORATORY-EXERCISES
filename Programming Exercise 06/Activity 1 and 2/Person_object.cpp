/*  CMSC 28 - Programming Exercise 06
    Activity 2
    Written By: Jodi C. Gabano */

#include <iostream>
#include <string>
#include "Person.h"
#include "Name.h"
using namespace std;

int main() {
  int a;
  char g;
  string fn;
  string ln;

  cout << "Creating the Person and Name object (p,n) using the Constructors" << endl;
  Person p;
  Name n;

  cout << "\nInput age: ";
  cin >> a;
  p.setage(a);
  p.generationage(a);

  cout << "Input gender: ";
  cin >> g;
  p.setgender(g);

  cin.get();

  cout << "Input first name: ";
  getline(cin, fn);
  n.setfname(fn);

  cout << "Input last name: ";
  getline(cin, ln);
  n.setlname(ln);

  cout << "\nAge = " << p.getage() << endl;
  cout << "Gender = " << p.getgender() << endl;
  cout << "Your Generation = " << p.generationage(a) << endl;
  cout << "First Name = " << n.getfname() << endl;
  cout << "Last Name = " << n.getlname() << endl;

  return 0;
}