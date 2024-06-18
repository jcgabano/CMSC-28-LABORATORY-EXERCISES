// Include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// create class Person
class Person {
// Declare private attributes
private:
    int age;
    char gender;
    string fname;
    string lname;
// Add new public attributes
public:
    string emailAdd;
    string cpNumber;

    // Default constructor
    Person() {}

    // Setter and Getter methods for each attribute
    // Error handling was added to validate input through sending messages to the main file
    void setage(int newage) {
        if (newage >= 0) {
            age = newage;
        } else {
            throw invalid_argument("Invalid age!");
        }
    }

    int getage() {
        return age;
    }

    void setgender(char c) {
        if (c == 'M' || c == 'F') {
            gender = c;
        } else {
            throw invalid_argument("Invalid gender! Please enter 'M' or 'F'.");
        }
    }

    char getgender() {
        return gender;
    }

    void setfname(string newfname) {
        fname = newfname;
    }

    string getfname() {
        return fname;
    }

    void setlname(string newlname) {
        lname = newlname;
    }

    string getlname() {
        return lname;
    }

    void setemailAdd(string newemailAdd) {
        emailAdd = newemailAdd;
    }

    string getemailAdd() {
        return emailAdd;
    }

    void setcpNumber(string newcpNumber) {
        cpNumber = newcpNumber;
    }

    string getcpNumber() {
        return cpNumber;
    }

    // Method to accept user input for the common attributes
    void input() {
        cout << "Enter first name: ";
        getline(cin, fname);

        cout << "Enter last name: ";
        getline(cin, lname);

        cout << "Enter gender (M/F): ";
        cin >> gender;
        cin.ignore(); // To ignore the newline character left by previous input
        setgender(gender); // validate input

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        setage(age); // validate input

        cout << "Enter email address: ";
        getline(cin, emailAdd);

        cout << "Enter contact number (+63): ";
        getline(cin, cpNumber);
    }
};

#endif // PERSON_H