/*External header file for activity 1.2*/

#include <iostream>
#include <string>

using namespace std;

class Candy {
  private:
    string name;
    string flavor;
    string candyType;

  public:
    Candy(string name, string flavor, string candyType)
    : name(name), flavor(flavor), candyType(candyType) {}

    void display() {
      cout << "Name: " << name << endl;
      cout << "Flavor: " << flavor << endl;
      cout << "Type: " << candyType << endl;
    }
};