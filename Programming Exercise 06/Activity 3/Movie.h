// include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "Person.h" // include the Person header file

using namespace std;

// Movie class constructor
class Movie {
  // Private attributes
  private:
    string title;
    string synopsis;
    string mpaa_rating;
    string genre;
    Person director; // Member of the Person class
    Person actor; // Member of the Person class

  // Public methods
  public:
    // Create a constructor
    Movie() {}

    // Adding parameters to the constructor
    Movie(string t, string s, string m, string g, Person d, Person a) {
      title = t;
      synopsis = s;
      mpaa_rating = m;
      genre = g;
      director = d;
      actor = a;
    }

    // Getter and setter functions for each member variable

    void setTitle(string t) {
      title = t;
    }

    string getTitle() {
      return title;
    }

    void setSynopsis(string s) {
      synopsis = s;
    }

    string getSynopsis() {
      return synopsis;
    }

    void setMpaaRating(string m) {
      mpaa_rating = m;
    }

    string getMpaaRating() {
      return mpaa_rating;
    }

    void setGenre(string g) {
      genre = g;
    }

    string getGenre() {
      return genre;
    }

    void setDirector(Person d) {
      director = d;
    }

    Person getDirector() {
      return director;
    }

    void setActor(Person a) {
      actor = a;
    }

    Person getActor() {
      return actor;
    }

    // Function to display movie details
    void display() {
      cout << "Movie Title: " << getTitle() << endl;
      cout << "Synopsis: " << getSynopsis() << endl;
      cout << "MPAA Rating: " << getMpaaRating() << endl;
      cout << "Genre: " << getGenre() << endl;
      // Display the director's full name and gender
      cout << "Director: " << getDirector().getFname() << " " << getDirector().getLname() << " (Gender: " << getDirector().getGender() << ")" << endl;
      // Display the actor's full name and gender
      cout << "Actor: " << getActor().getFname() << " " << getActor().getLname() << " (Gender: " << getActor().getGender() << ")" << endl;
    }
};

#endif // MOVIE_H