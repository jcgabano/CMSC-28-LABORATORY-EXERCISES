// Include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h" // include person header file to inherit the attributes
#include <iostream>
#include <string>
#include <regex>
using namespace std;

// create class Student with inherited attributes and methods from class Person
class Student : public Person {
// declare private attributes
  private:
    string studentNum;
// declare public attributes
  public:
    string Course;
    string Department;
    string College;

    // defualt constructor
    Student(){}

  // setter and getter methods for each attribute
// Error handling was added to validate input through sending messages to the main file
  void setstudentNum(string newstudentNum){
    studentNum = newstudentNum;
  }

  string getstudentNum(){
    return studentNum;
  }

  void setCourse(string newCourse){
    Course = newCourse;
  }
  string getCourse(){
    return Course;
  }

  void setDepartment(string newDepartment){
    Department = newDepartment;
  }
  string getDepartment(){
    return Department;
  }

  void setCollege(string newCollege){
    College = newCollege;
  }
  string getCollege(){
    return College;
  }

  // method to validate student number format
  bool isValidStudentNumber(const string& studentNum) {
      // Regular expression to match the format 20xx-12345
      regex pattern("^20\\d{2}-\\d{5}$");
      return regex_match(studentNum, pattern);
  }



  // Method to accept user input for the student attributes
void inputStudent() {

    cout << "Enter Student Number (format 20xx-12345): ";
    getline(cin, studentNum);
    while (!isValidStudentNumber(studentNum)) {
        cout << "Invalid student number format. Please try again." << endl;
        cout << "Enter Student Number (format 20xx-12345): ";
        getline(cin, studentNum);
    }
    setstudentNum(studentNum); // Set the student number

    cin.clear();

    cout << "Enter Course: ";
    getline(cin, Course);

    cout << "Enter Department: ";
    getline(cin, Department);

    cout << "Enter College: ";
    getline(cin, College);
}


  // output the program message
  void output(){
    cout << "\nHi, " << getfname() << " " << getlname() << "! Welcome to UP Mindanao and congratulations! We are pleased to inform you are admitted in the " << getCourse() << " under the Department of " << getDepartment() << ", at the College of " << getCollege() << ". Your Student number is " << getstudentNum() << "." << endl;
    cout << "\n Don't forget to check your email " << getemailAdd() << " or SMS inbox at +63" << getcpNumber() << " for the confirmation of your admission. Thank you!" << endl;
  }

  // Override input function to include student attributes
  void input() {
      Person::input(); // Call base class input function to input common attributes
      inputStudent(); // Call derived class input function to input student attributes
  }
};

#endif // STUDENT.H