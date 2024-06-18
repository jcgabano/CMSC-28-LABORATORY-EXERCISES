/* CMSC 28 - Programming Exercise 04: Problem 1
   Written By: Jodi C. Gabano
*/

#include <iostream>

using namespace std;

// function to display the program description
void progdescription() {
    cout << "This program finds the highest and lowest numbers and outputs their difference." << endl;
    cout << "Programmer: Jodi C. Gabano" << endl;
    cout << "Date: 4/27/24" << endl;
    cout << "Subject: CMSC 28\n" << endl;
}

// function to get and store the inputted numbers
void readdata(int &x, int &y, int &z) {
    cout << "Enter three numbers: (x y z)\n";
    cin >> x >> y >> z;
}

// function to find the largest number uses control statements to compare all 3 numbers
int getlarge(int x, int y, int z) {
    int largest = x;
    if (y > largest)
        largest = y;
    if (z > largest)
        largest = z;
    return largest;
}

// function to find the smallest number uses control statements to compare all 3 numbers
int getsmall(int x, int y, int z) {
    int smallest = x;
    if (y < smallest)
        smallest = y;
    if (z < smallest)
        smallest = z;
    return smallest;
}

// function displays all the data and the difference of the largest and smallest numbers
void showdata(int x, int y, int z, int largeval, int smallval, int diff) {
    cout << "\nNumbers Entered: " << x << " " << y << " " << z << endl;
    cout << "Largest Number: " << largeval << endl;
    cout << "Smallest Number: " << smallval << endl;
    cout << "Difference: " << diff << endl;
}

// main program
int main(){
// variable declarations
int x, y, z, smallval, largeval, diff;

// function call to diplay the program description
progdescription();

// function call to get the value stored in x, y, and z
readdata(x, y, z);

// function call to get the smallest number out of the 3 and return it to the main program
smallval = getsmall(x, y, z);

// function call to get the largest number out of the 3 and return it to the main program
largeval = getlarge(x, y, z);

// assigning a value to the difference variable
diff = largeval-smallval;

// function call to display the data
showdata(x, y, z, largeval, smallval, diff);

return 0;

}