/*  CMSC 28 - Programming Exercise 06
    Activity 1.2
    Written By: Jodi C. Gabano */

#include <iostream>
#include "Candy.h" // include the external header file

using namespace std;

int main() {
  cout << "Displaying the Input: " << endl;
  Candy candyshop1("Potchi", "Strawberry", "Gummy");
  candyshop1.display();

  return 0;
}