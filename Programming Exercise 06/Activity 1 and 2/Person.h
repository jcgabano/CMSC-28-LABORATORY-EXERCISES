/*Person external header file for activity 2*/

#include <iostream>

using namespace std;

class Person{
  private:
    int age;
    char gender;

  public:
    Person(){}

  Person(int newage){
    age = newage;
    gender = 'M';
  }

  Person(int newage, char c){
    age = newage;
    gender = c;
  }

  void setage(int newage){
    if(newage>=0){
      age = newage;
    } else {
      cout << "Invalid age!!!" << endl;
    }
  }

  string generationage(int newage) {
    if (newage >= 97 && newage <= 123) {
      return "You are the Greatest Generation";
    } else if (newage >= 79 && newage <= 96) {
      return "You are the Silent Generation";
    } else if (newage >= 60 && newage <= 78) {
      return "You are the BOOMERS";
    } else if (newage >= 44 && newage <= 59) {
      return "You are the GENERATION X";
    } else if (newage >= 28 && newage <= 43) {
      return "You are the MILLENIALS";
    } else if (newage >= 14 && newage <= 27) {
      return "You are the GENERATION Z";
    } else if (newage >= 0 && newage <= 13) {
      return "You are the GENERATION ALPHA";
    } else {
      return "Invalid age";
    }
  }

  int getage(){
    return age;
  }

  void setgender(char c){
    if(c=='M' || c=='F'){
      gender = c;
    } else {
      cout << "Invalid gender!!!" << endl;
    }
  }

  char getgender(){
    return gender;
  }

  void view(){
    cout << "Person age is = " << getage() << endl;
    cout << "Person gender is = " << getgender() << endl;
  }

  void view(int age){
    cout << "Person age is = " << getage() << endl;
    cout << "Person gender is = " << getgender() << endl;
  }

  void view(int age, char gender){
    cout << "Person age is = " << age << endl;
    cout << "Person gender is = " << gender << endl;
  }
};