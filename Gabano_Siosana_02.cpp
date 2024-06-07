/* PE03 - Stack Implementation
   Written by: Jodi Gabano & Cedric Siosana
   Date: March 22, 2024  */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// creating the node
struct Node {
  string element;
  Node *next;
};

// creating the stack
struct Stack {
  // Initializing parts of the stack
private:
  Node *top; // pointer to the top of the stack
  int size;
  int max_size;

public:
  // construct to initialize the stack
  Stack(int max) {
    top = nullptr;
    size = 0;
    max_size = max;
  }

  // function to push a string to the stack
  void PUSH(string x) {
    // first check if the stack is full before adding an element
    if (FULL()) {
      cout << "\n\nThe STACK is FULL. Cannot add kitchenware\n\n" << endl;
      return;
    }
    // If the stack is not full, then add the element to the stack
    Node *newNode = new Node();
    newNode->element = x;
    newNode->next = top;
    top = newNode;
    // increment the size of the stack to keep track of the number of elements
    size++;
  }

  // function to pop a string from the stack
  void POP() {
    // Check if the stack is empty before removing an element
    if (EMPTY()) {
      cout << "The STACK is EMPTY. No more kitchenware to wash" << endl;
      return;
      // If the stack is not empty, then remove the element from the stack using
      // a temporary node
    } else {
      Node *temp = top;
      top = top->next;
      delete temp;
      // decrement the size of the stack to keep track of the number of elements
      size--;
    }
  }

  // function to display the stack
  void display() {
    // Check if stack is empty before displaying the elements
    if (EMPTY()) {
      cout << "STACK is EMPTY" << endl;
      return;
    }
    // If the stack is not empty, then display the elements of the stack
    Node *temp = top;
    // use a temp node to go through each element in the stack
    cout << "STACK elements are: \n";
    // The loop runs as the temp node goes through each node and displays the
    // elements like an actual stack, until it reaches the end
    while (temp != nullptr) {
      cout << "[" << temp->element << "]" << endl;
      temp = temp->next;
    }
    cout << endl;
  }

  // function to check if the stack is empty
  bool EMPTY() {
    // If the top is pointing to nullptr, then the stack is empty and the
    // program will return true
    if (top == nullptr) {
      return true;
      // If the top is not pointing to nullptr, then the stack is not empty and
      // the program will return false
    } else {
      return false;
    }
  }

  // function to check if the stack is full
  bool FULL() { return size >= max_size; }

  // function to return the top element of the stack
  string TOP() {
    if (!EMPTY()) {
      return top->element;
    } else {
      cout << "STACK is EMPTY." << endl;
      return "";
    }
  }

  // function to empty the stack
  void MAKENULL() {
    // loop through each element and delete them
    while (!EMPTY()) {
      cout << TOP() << " is being washed. " << endl;
      POP();
    }
    cout << "\nAll kitchenware has been washed." << endl;
  }
};

void mainMenu(Stack stk) {
  int choice = 0;

  cout << "Kitchenware Washing Machine" << endl;

  do {

    cout << "\n[1] Add kitchenware\n[2] Wash kitchenware\n[3] Top "
            "kitchenware\n[4] Wash all\n[0] Exit\n\nEnter choice: ";

    cin >> choice;

    // This is an error catcher, if not any of the choices, it will display an
    // error message and ask the user to input again.
    if (!(choice >= 0 && choice <= 4)) {
      cout << "\n\nYou have entered an invalid choice, please try again...\n\n";
    }

    // Variable necessary for the program.
    string userInput;

    switch (choice) {
      //This case will add a kitchenware to the stack.
    case 1:
      cout << "\nEnter kitchenware to be washed: ";
      cin.ignore(); // ignore any newlines
      getline(cin, userInput); // get the whole line (accepts more than one word)
      stk.PUSH(userInput);
      break;

      //This case will remove a kitchenware from the stack.
    case 2:
      if (stk.EMPTY()) {
        cout << "\n\nThe STACK is EMPTY. No more kitchenware to wash\n\n";
      } else {
        cout << stk.TOP() << " is being washed." << endl;
        stk.POP();
      }
      break;

      //This case will display the top element of the stack.
    case 3:
      if (stk.EMPTY()) {
        cout << "\n\nThe STACK is EMPTY. No more kitchenware to wash\n\n";
      } else {
        cout << "\n" << stk.TOP() << " is next to be washed." << endl;
      }
      break;

      //This will delete all of the kitchenware from the stack.
    case 4:
      if (stk.EMPTY()) {
        cout << "\n\nThe STACK is EMPTY. No more kitchenware to wash\n\n"
             << endl;
      } else {
        //The MAKENULL function is being called to empty the stack
        stk.MAKENULL();
      }
      break;

      //This case will exit the program.
    case 0:
      cout << "\n\nWashing machine process has been terminated.\n\n";
      break;
    }

  } while (choice != 0);
}

int main() {
  int max_size = 10;
  Stack stk(max_size);
  //This is the main menu function that will be called in the main function
  mainMenu(stk);
}