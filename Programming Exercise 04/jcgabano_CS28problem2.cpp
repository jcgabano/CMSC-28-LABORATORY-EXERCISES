/* CMSC 28 - Programming Exercise 04: Problem 2
   Written By: Jodi C. Gabano
*/

#include <iostream>

using namespace std;

// function to display the program description
void progdescription() {
    cout << "This program converts decimal numbers to its binary equivalent" << endl;
    cout << "Programmer: Jodi C. Gabano" << endl;
    cout << "Date: 4/27/24" << endl;
    cout << "Subject: CMSC 28\n" << endl;
}

// function to get and store the inputted numbers
void readdata(int &decNum) {
    cout << "Enter a Decimal Number: \n";
    cin >> decNum;
}

// function to convert the decimal input into its binary equivalent
int decimalToBinary(int num, int binaryNum[]) {
    int i = 0; // declaring i as a counter

    // the loop divides the binary number by 2 until it reaches 0 and stores the remainder into the array for each iteration of the loop
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++; // increments after each iteration to prevent an infinite loop
    }

    // return the position where the last digit was stored in the array
    return i;
}

// function to display the binary number stored in the array
void showdata(int binaryNum[], int newNum, int decNum) {
    // display the binary equivalent by going through each digit in the array starting from the last digit
    // until the first digit, just like when solving manually you have to sort the remainder from bottom to top.
    cout << "\nDecimal Number: " << decNum;
    cout << "\nBinary Equivalent: ";
    for (int j = newNum - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
    cout << endl;
}

int main() {
    int decNum;
    int binaryNum[32]; // declaring an array to store each binary digit

    // function call to display the program description and get the decimal number from the user
    progdescription();
    readdata(decNum);

    // function call to get the binary equivalent and store it to variable newNum
    int newNum = decimalToBinary(decNum, binaryNum);

    // function call to display all the data
    showdata(binaryNum, newNum, decNum);

    return 0;
}