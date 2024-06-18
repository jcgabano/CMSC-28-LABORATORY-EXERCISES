// include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
  private:
    string fname;
    string lname;
    char gender;

  public:
    Person() {}

    Person(string fn, string ln, char gr) {
      fname = fn;
      lname = ln;
      setGender(gr); // Use setGender to handle validation
    }

    void setFname(string fn) {
      fname = fn;
    }

    string getFname() {
      return fname;
    }

    void setLname(string ln) {
      lname = ln;
    }

    string getLname() {
      return lname;
    }

    void setGender(char gr) {
      if (gr == 'M' || gr == 'm' || gr == 'f' || gr == 'F') {
        gender = gr;
      } else {
        cout << "Invalid gender!!! \nProgram will terminate." << endl;
        exit(EXIT_FAILURE);  // Terminate the program with an error code
      }
    }

    char getGender() {
      return gender;
    }
};

#endif // PERSON_H