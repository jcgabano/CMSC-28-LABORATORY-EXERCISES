/* CMSC 28 - Programming Exercise 08 */

// include the external header files
#include "Employees.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Print program information
    cout << "This program shows class inheritance through class Employees." << endl;
    cout << "\nProgrammed by: Jodi C. Gabano\n" << endl;
    cout << "=======================================" << endl;

    cout << "\nInput Employee Information:" << endl;

    Employees employee; // creating an instance of class Employees
    // Accepts input while executing the error statements
    try {
        // Accept user input for employee attributes
        employee.input();
    } catch (const invalid_argument& e) {
        // Handle invalid input exceptions
        cerr << "Error: " << e.what() << endl;
        return 1; // Exit with error code
    }

    // Display the employee details using getter methods
    cout << "\nEmployee Details:" << endl;
    cout << "Name: " << employee.getfname() << " " << employee.getlname() << endl;
    cout << "Gender: " << employee.getgender() << endl;
    cout << "Age: " << employee.getage() << endl;
    cout << "Employee Number: " << employee.getempNum() << endl;
    cout << "Position: " << employee.getPosition() << endl;
    cout << "Office: " << employee.getOffice() << endl;
    cout << "Salary: " << employee.getSalary() << endl;
    // display the output message
    employee.output();

    return 0;
}