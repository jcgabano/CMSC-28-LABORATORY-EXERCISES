/*  CMSC 28 - Programming Exercise 06
    Activity 3
    Written By: Jodi C. Gabano      */

#include <iostream>
#include <string>
#include "Person.h" // Include the Person header file
#include "Movie.h" // Include the Movie header file

using namespace std;

int main() {
  // Declare variables to store movie details
  string title, synopsis, mpaa_rating, genre;
  string directorFname, directorLname, actorFname, actorLname;
  char directorGender, actorGender;

  // Print program information
  cout << "This program displays a movie's details, using separate classes and external files for Movie and Person, and demonstrates the get and set functions of these classes." << endl;
  cout << "\nProgrammed by: Jodi C. Gabano\n" << endl;
  cout << "=======================================" << endl;

  // Prompt the user to enter movie details
  cout << "\nEnter Movie Title: ";
  getline(cin, title);

  cout << "Enter Synopsis: ";
  getline(cin, synopsis);

  cout << "What is its MPAA Rating: ";
  getline(cin, mpaa_rating);

  cout << "What is the Genre: ";
  getline(cin, genre);

  // Prompt user to enter director's details
  cout << "Enter the director's first name: ";
  getline(cin, directorFname);
  cout << "Enter the director's last name: ";
  getline(cin, directorLname);
  cout << "Enter the director's gender (M/F): ";
  cin >> directorGender;
  cin.get(); // Clear the input buffer to avoid errors

  // Create a Director object with user input
  Person director;
  director.setFname(directorFname);
  director.setLname(directorLname);
  director.setGender(directorGender); // Use setGender for error handling

  // Prompt user to enter actor's details
  cout << "Enter the actor's first name: ";
  getline(cin, actorFname);
  cout << "Enter the actor's last name: ";
  getline(cin, actorLname);
  cout << "Enter the actor's gender (M/F): ";
  cin >> actorGender;
  cin.get(); // Clear the input buffer to avoid errors

  // Create an Actor object with user input
  Person actor;
  actor.setFname(actorFname);
  actor.setLname(actorLname);
  actor.setGender(actorGender); // Use setGender for error handling

  // Create a Movie object with user input
  Movie movie(title, synopsis, mpaa_rating, genre, director, actor);
  cout << "\n"; // for readability
  movie.display(); // Display movie details by calling the function in the constructor

  return 0;
}