/*  CMSC 28 - Programming Exercise 06 
    Activity 1.1
    Written By: Jodi C. Gabano */

#include <iostream>

using namespace std;

// class constructor
  class Candy {
    // private features/attributes
    private:
      string name;
      string flavor;
      string candyType;

    // public methods to establish the constructor
    public:
      Candy(string name, string flavor, string candyType)
      : name(name), flavor(flavor), candyType(candyType) {}

    // display the values
      void display() {
        cout << "Name: " << name << endl;
        cout << "Flavor: " << flavor << endl;
        cout << "Type: " << candyType << endl;
      }
  };

int main() {
  
  cout << "Displaying the Input: " << endl;
  // creating a instance of the class and sending input
  Candy candyshop1("Potchi", "Strawberry", "Gummy");
  candyshop1.display(); // display the input using the function

  return 0;
}