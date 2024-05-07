/* CMSC 28 PROGRAMMING EXERCISE 05 
   Written By: Jodi C. Gabano
   Date: 5/8/24                   */

#include <iostream>
#include <iomanip> // For the setprecision function
#include <cmath> // For the power and sqrt function

using namespace std;

#define arrSize 10 // Defining the array size as a constant

// Function declarations
int dataEntry(int userArray[arrSize]);
int findLargest(int userArray[arrSize]);
int findSmallest(int userArray[arrSize]);
float dataAverage(int userArray[arrSize]);
float dataSTDEV(int userArray[arrSize], float averageNum);
float dataVariance(int userArray[arrSize], float averageNum);
void outputDisplay(int largestNum, int smallestNum, float averageNum, float stdevNum, float varNum);

// Function to collect the data inputted by the user
int dataEntry(int userArray[arrSize]) {
    int i;
    // The loop asks for an integer and stores it in the array until the array reaches 10 elements
    for (i=0; i<arrSize; i++) {
        cout << "Input an Integer: ";
        cin >> userArray[i];
    }
    return *userArray; // Return the new array
}

// Function to find the largest number in the array
int findLargest(int userArray[arrSize]) {
    int largest = userArray[0]; // Assume the first element is the largest number
    int i;
    // The loop goes through each value and if that value is larger than the current largest value then that value will be assigned as the new largest value
    for (i=1; i<arrSize; i++) {
        if (userArray[i] > largest) {
            largest = userArray[i];
        }
    }
    return largest; // Return the largest number to main
}

// Find the smallest number in the array
int findSmallest(int userArray[arrSize]) {
    int smallest = userArray[0]; // Assume the first element is the smallest number
    int i;
    // The loop goes through each value and if that value is smaller than the current smallest value then that value will be assigned as the new smallest value
    for (i=1; i<arrSize; i++) {
        if (userArray[i] < smallest) {
            smallest = userArray[i];
        }
    }
    return smallest; // Return the smallest number to main
}

// Function to get the average (mean) of the elements in the array
float dataAverage(int userArray[arrSize]) {
    float sum=0; // Initialize sum to 0
    int i;
    // The loop sums each value of the array together
    for (i=0; i<arrSize; i++) {
        sum += userArray[i];
    }
    return sum/arrSize; // Return the sum divided by the array size to get the average
}

// Function to get the population standard deviation of the elements in the array
float dataSTDEV(int userArray[arrSize], float averageNum) {
    float stdev=0; // Initialize stdev to 0
    int i;
    // The loop goes through each element in the array and does the following:
    // i. minuses the average from the current element
    // ii. raise that number to the power of 2
    // iii. add all the values from the loop together
    for (i=0; i<arrSize; i++) {
        stdev += pow(userArray[i] - averageNum, 2); // Using the pow and sqrt function for easier and more accurate computations
    }
    return sqrt(stdev/arrSize); // Return the square root of the stdev divided by the array size to get the final stdev
}

// Function to get the variance of the elements in the array
float dataVariance(int userArray[arrSize], float averageNum) {
    float variance = 0; // Initialize variance to 0
    int i;
    // The loop goes through each element in the array and does the following:
    // i. minuses the average from the current element
    // ii. raise that number to the power of 2
    // iii. add all the values from the loop together
    for (i=0; i<arrSize; i++) {
        variance += pow(userArray[i] - averageNum, 2); // Using the pow function for easier and more accurate computations
    }
    return variance/arrSize; // Return the variance divided by the array size to get the final variance
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
    int userArray[arrSize], largestNum, smallestNum;
    float averageNum, stdevNum, varNum;

    // Program description
    cout << "Programming Exercise 05" << endl;
    cout << "Submitted by:  Jodi C. Gabano" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "This program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n" << endl;

    // Function calls to get each value
    dataEntry(userArray); // Asks the user to input values into the array
    largestNum = findLargest(userArray); // Gets the largest number in the array
    smallestNum = findSmallest(userArray); // Gets the smallest number in the array
    averageNum = dataAverage(userArray); // Gets the average value of the data
    stdevNum = dataSTDEV(userArray, averageNum); // Gets the population standard deviation of the data
    varNum = dataVariance(userArray, averageNum); // Gets the variance of the data
    outputDisplay(largestNum, smallestNum, averageNum, stdevNum, varNum); // Displays the data, this is the only void function.

    return 0;
}