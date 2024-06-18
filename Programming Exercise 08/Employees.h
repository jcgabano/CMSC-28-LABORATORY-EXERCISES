// Include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Person.h" // include person header file to inherit the attributes
#include <iostream>
#include <string>
using namespace std;

// create class Employees with inherited attributes and methods from class Person
class Employees : public Person {
// declare private attributes
private:
    int empNum;
// declare public attributes and methods
public:
    string Position;
    string Office;
    float Salary;

    // default constructor
    Employees() {}

    // getter and setter methods for each attribute
// Error handling was added to validate input through sending messages to the main file
    void setempNum(int newempNum) {
        // Ensure the employee number is exactly 5 digits long
        if (newempNum >= 10000 && newempNum <= 99999) {
            empNum = newempNum;
        } else {
          throw invalid_argument("Invalid employee number! It should be a 5-digit number.");
        }
    }

    int getempNum() {
        return empNum;
    }

    void setPosition(string newPosition) {
        Position = newPosition;
    }

    string getPosition() {
        return Position;
    }

    void setOffice(string newOffice) {
        Office = newOffice;
    }

    string getOffice() {
        return Office;
    }

    void setSalary(float newSalary) {
        if (newSalary >= 0) {
            Salary = newSalary;
        } else {
            throw invalid_argument("Invalid salary!");
        }
    }

    float getSalary() {
        return Salary;
    }

    // Method to accept user input for the employee attributes
    void inputEmployee() {
        cout << "Enter employee number (5 digits): ";
        cin >> empNum;
        cin.ignore(); // To ignore the newline character left by previous input
        setempNum(empNum); // Validate input

        cout << "Enter position: ";
        getline(cin, Position);

        cout << "Enter office: ";
        getline(cin, Office);

        cout << "Enter salary: ";
        cin >> Salary;
        cin.ignore();
        setSalary(Salary); //validate input
    }

    // output the program message
    void output(){
      cout << "\nHi, " << getfname() << " " << getlname() << "! Welcome to UP Mindanao! We are pleased to inform you that you have been hired for the position of " << getPosition() << " at the Office of " << getOffice() << ". Your Employee number is " << getempNum() << "." << endl;

    cout << "\n Don't forget to check your email " << getemailAdd() << " or SMS inbox at +63" << getcpNumber() << " for the confirmation of your new position. Thank you!" << endl;
    }

    // Override input function to include employee attributes
    void input() {
        Person::input(); // Call base class input function to input common attributes
        inputEmployee(); // Call derived class input function to input employee attributes
    }
};

#endif // EMPLOYEES_H