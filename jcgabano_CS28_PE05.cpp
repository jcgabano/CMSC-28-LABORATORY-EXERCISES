/* CMSC 28 PROGRAMMING EXERCISE 05 
   Written By: Jodi C. Gabano
   Date: 5/8/24                   */

#include <iostream>
#include <iomanip> // For the setprecision function
#include <cmath> // For the power and sqrt function

using namespace std;

// Function declarations
int dataEntry(int userArray[]);
int findLargest(int userArray[], int count);
int findSmallest(int userArray[], int count);
float dataAverage(int userArray[], int count);
float dataSTDEV(int userArray[], float averageNum, int count);
float dataVariance(int userArray[], float averageNum, int count);
void outputDisplay(int largestNum, int smallestNum, float averageNum, float stdevNum, float varNum, int count);

// Function to collect the data inputted by the user
int dataEntry(int userArray[]) {
    int i;
    // Initialize the array with 0
    for (i=0; i<10; i++) {
        userArray[i] = 0;
    }
    // The loop asks for an integer and stores it in the array until the array reaches 10 elements
    for (i=0; i<10; i++) {
        cout << "Input an Integer: ";
        cin >> userArray[i];
        if (userArray[i] == 0) {
            break;
        }
    }
    return *userArray; // Return the new array
}

// Function to find the largest number in the array
int findLargest(int userArray[], int count) {
    int largest = userArray[0]; // Assume the first element is the largest number
    int i;
    // The loop goes through each value and if that value is larger than the current largest value then that value will be assigned as the new largest value
    for (i=1; i<count; i++) {
        if (userArray[i] > largest) {
            largest = userArray[i];
        }
    }
    return largest; // Return the largest number to main
}

// Find the smallest number in the array
int findSmallest(int userArray[], int count) {
    int smallest = userArray[0]; // Assume the first element is the smallest number
    int i;
    // The loop goes through each value and if that value is smaller than the current smallest value then that value will be assigned as the new smallest value
    for (i=1; i<count; i++) {
        if (userArray[i] < smallest) {
            smallest = userArray[i];
        }
    }
    return smallest; // Return the smallest number to main
}

// Function to get the average (mean) of the elements in the array
float dataAverage(int userArray[], int count) {
    float sum=0; // Initialize sum to 0
    int i;
    // The loop sums each value of the array together
    for (i=0; i<count; i++) {
        sum += userArray[i];
    }
    return sum/count; // Return the sum divided by the array size to get the average
}

// Function to get the population standard deviation of the elements in the array
float dataSTDEV(int userArray[], float averageNum, int count) {
    float stdev=0; // Initialize stdev to 0
    int i;
    // The loop goes through each element in the array and does the following:
    // i. minuses the average from the current element
    // ii. raise that number to the power of 2
    // iii. add all the values from the loop together
    for (i=0; i<count; i++) {
        stdev += pow(userArray[i] - averageNum, 2); // Using the pow and sqrt function for easier and more accurate computations
    }
    return sqrt(stdev/count); // Return the square root of the stdev divided by the array size to get the final stdev
}

// Function to get the variance of the elements in the array
float dataVariance(int userArray[], float averageNum, int count) {
    float variance = 0; // Initialize variance to 0
    int i;
    // The loop goes through each element in the array and does the following:
    // i. minuses the average from the current element
    // ii. raise that number to the power of 2
    // iii. add all the values from the loop together
    for (i=0; i<count; i++) {
        variance += pow(userArray[i] - averageNum, 2); // Using the pow function for easier and more accurate computations
    }
    return variance/count; // Return the variance divided by the array size to get the final variance
}

// Function to display all the data
void outputDisplay(int largestNum, int smallestNum, float averageNum, float stdevNum, float varNum) {
    cout << "\nLargest = " << largestNum << endl;
    cout << "Smallest = " << smallestNum << endl;
    cout << fixed << setprecision(2); // The following values will be displayed with 2 decimal places using setprecision
    cout << "Average = " << averageNum << endl;
    cout << "Standard Deviation = " << stdevNum << endl;
    cout << "Variance = " << varNum << endl;
}

// Main program
int main() {
    // Variable declarations
    int userArray[10], largestNum, smallestNum, i;
    float averageNum, stdevNum, varNum;

    // Program description
    cout << "Programming Exercise 05" << endl;
    cout << "Submitted by:  Jodi C. Gabano" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "This program will ask the user to input ten numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n" << endl;

    // Function Call
    dataEntry(userArray); // Asks the user to input values into the array
    int count = 0; // Initialize a counter to get the number of elements in the array
    for (i=0;i<=10;i++) {
        if (userArray[i] != 0 || i == 10 - 1) { // include 0's in the count
            count++; // increments once an element is found
        } // the count value will be passed to the functions to perform the proper calculations
    }

    // Function Calls
    largestNum = findLargest(userArray, count); // Gets the largest number in the array
    smallestNum = findSmallest(userArray, count); // Gets the smallest number in the array
    averageNum = dataAverage(userArray, count); // Gets the average value of the data
    stdevNum = dataSTDEV(userArray, averageNum, count); // Gets the population standard deviation of the data
    varNum = dataVariance(userArray, averageNum, count); // Gets the variance of the data
    outputDisplay(largestNum, smallestNum, averageNum, stdevNum, varNum); // Displays the data, this is the only void function.

    return 0;
}