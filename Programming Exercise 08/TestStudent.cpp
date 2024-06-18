/* CMSC 28 - Programming Exercise 08 */

// Include the external header files
#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <regex>

int main() {

    // Print program information
    cout << "This program shows class inheritance through class Person and class Student." << endl;
    cout << "\nProgrammed by: Jodi C. Gabano\n" << endl;
    cout << "=======================================" << endl;

    cout << "\nInput All Student Information:" << endl;

  Student student1; // creating an instance of class Student
  // Accepts input while executing the error statements
  try {
      // Accept user input for student attributes
      student1.input();
  } catch (const invalid_argument& e) {
      // Handle invalid input exceptions
      cerr << "Error: " << e.what() << endl;
      return 1; // Exit with error code
  }

  // Display the student details using getter methods
  cout << "\nStudent Details:" << endl;
  cout << "Name: " << student1.getfname() << " " << student1.getlname() << endl;
  cout << "Gender: " << student1.getgender() << endl;
  cout << "Age: " << student1.getage() << endl;
  cout << "Student Number: " << student1.getstudentNum() << endl;
  cout << "Course: " << student1.getCourse() << endl;
  cout << "Department: " << student1.getDepartment() << endl;
  cout << "College: " << student1.getCollege() << endl;
  // display the output message
  student1.output();

  return 0;
}