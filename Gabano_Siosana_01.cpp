/* PE01 - Linked List Implementation
   Written by: Jodi Gabano & Cedric Siosana
   Date: March 11, 2024  */


/*
The program is an implementation of a linked list where each node stores an
integer value. The program allows the user to do various operations, such as
adding an item, deleting a node, displaying, and deleting the entire list itself. The
adding feature enables the user to add at the beginning, at the end of the list
or a specified position (if the location is beyond the last node's location then
the new input is placed as the new last node), the deleting feature allows the
user to delete the node that has the first instance of the value of interest.
The deleting of the entire list, as the name suggest allows the user to
delete the entire list. The display feature allows the user to display the
entire list. We chose to write this program using C++ for it's added fatures.
*/

#include <iostream>

using namespace std;

// Declaring the structure for the linked list
struct Node {
  int item;   // the item stored in the node
  Node *next; // pointer to the next node
};

int DisplayMenu();            // function to display the menu
int getLength(Node *head);    // function to get the length of the list
void AddItem(Node *&head);    // function to add an item to the list
void DeleteItem(Node *&head); // function to delete an item from the list
void DisplayList(Node *head); // function to display the list
void DeleteList(Node *&head); // function to delete the entire list

int main() {
  Node *head = nullptr;
  int choice = 0;

  // The do-while function will keep on prompting the user unless the user
  // chooses to exit the program [choice 0].
  do {
    // This will call on the function to prompt the user to choose an option from the menu. It will
    // update choice as the do-while loop is executed.
    choice = DisplayMenu();
    switch (choice) {
    case 1:
      AddItem(head);
      break;
    case 2:
      DeleteItem(head);
      break;
    case 3:
      DisplayList(head);
      break;
    case 4:
      DeleteList(head);
      break;
    default:
      // This will handle instance where the user enters a number that is not
      // within the range of the menu.
      if (choice != 0) {
        cout << "Invalid choice. Please try again." << endl;
      }
    }
  } while (choice != 0);

  // The program successfully terminates when the user chooses to exit the
  // program [choice 0].
  cout << "You have successfully exited the program." << endl;

  return 0;
}

// This function will display the menu and return the user's choice.
int DisplayMenu() {
  int choice;
  cout << "\nList MENU:";
  cout << "\n[1] Add Item\n[2] Delete Item\n[3] Display List\n[4] Delete "
          "List\n[0] Exit Program";
  cout << "\nEnter Choice: ";
  cin >> choice;

  return choice;
}

// Getting the length for the add item function
int getLength(Node *head) {
  int length = 0;
  Node *temp = head;
  // Loops through the list until the temp node reaches the end or a null pointer
  while (temp != nullptr) {
    length++;
    temp = temp->next;
  }
  return length;
}

// Function to add an item to the list
void AddItem(Node *&head) {
  int item;
  cout << "Please enter the item to be added: ";
  cin >> item;

  // Displaying the sub menu so the user can select where to add the item
  int option = 0;
  cout << "\nWhere to add the item?";
  cout << "\n[1] Start of the list\n[2] End of the list\n[3] Specific "
          "position\n[0] Cancel";
  cout << "\nEnter Choice: ";
  cin >> option;

  // Creating a new node for the item
  Node *newNode = new Node;
  newNode->item = item;

  // The switch function will handle the user's choice for where to add the item.
  switch (option) {
  // Option 1 adds the item to the start of the list by assigning the head as the newNode
  case 1:
    newNode->next = head;
    head = newNode;
    break;
  // Option 2 adds the item to the end of the list by first assigning it's pointer to
  // null and going through the list until it reaches the end, then assigning that position
  // to the newNode
  case 2:
    newNode->next = nullptr;
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    break;
  // Option 3 adds the item to a specific position in the list
  case 3:
    int position, length;
    length = getLength(head); // Get the length of the list by calling on the function
    cout << "Enter the position to insert the item: ";
    cin >> position;

    // Check if position is out of bounds
    // If it is then add item to the end of the list
    if (position < 0 || position > length) {
      cout << "Position is out of bounds. Adding the item to the end of the list." << endl;
      newNode->next = nullptr;
      if (head == nullptr) {
        head = newNode;
      } else {
        Node *temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }
    // If the user chooses 0, add item to the start of the list
    else if (position == 0) {
      newNode->next = head;
      head = newNode;
    }
    // If the position is in the list, loop through the list until the position
    // is reached and add the item to the specified position
    else {
      Node *temp = head;
      for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
    }
    break;
  // Add item operation is canceled when the user's choice is 0
  case 0:
    cout << "Adding item canceled." << endl;
    delete newNode;
    break;
  // By default the operation will cancel if the user's choice is not
  // within the range of the menu
  default:
    cout << "Invalid choice. Adding item canceled." << endl;
    delete newNode;
  }
}

// Function to delete an item from the linked list
void DeleteItem(Node *&head) {
  // These will declare all of the necessary variables for the function to use.
  int num;
  Node *temp = head;
  Node *prev = nullptr;
  int iterator = 1;

  // These 2 lines will prompt the user to enter the item to be deleted.
  cout << "Enter the item to be deleted: ";
  cin >> num;

  // This while-loop will keep on iterating on each node until the very end of
  // the list until the item is found
  while (temp != nullptr) {
    if (temp->item ==
        num) { // If the item is found, then the node will be deleted
      if (prev == nullptr) { // Deleting the head
        head = temp->next;
        cout << "The element " << num << " which is at position " << iterator
             << " has been deleted" << endl;
      } else { // In the event where the item is not the head
        prev->next = temp->next;
        cout << "The element " << num << " which is at position " << iterator
             << " has been deleted" << endl;
      }
      // This is the deletion of the node.
      delete temp;
      return;
    }
    // These 3 lines of code will update the previous node, the current node,
    // and the iterator
    prev = temp;
    temp = temp->next;
    iterator++;
  }
  cout << "The list contains no such element" << endl;
}

// This function will display the list, meaning all of the nodes that have been
// created during the program runtime will be displayed.
void DisplayList(Node *head) {
  // This is the iterator, it will count how many nodes have been passed through.
  int iterator = 1;
  // This creates and equates the temp node to the head.
  Node *temp = head;

  // This is the consideration in the event where the list is empty, this can be
  // found out if head is equal to null.
  if (head == nullptr) {
    cout << "The list is empty" << endl;
    return;
  }

  // The following lines will be for printing the nodes and their positions.
  // This is possible by updating the iterators and printing the nodes and
  // iterator. The while function will keep on iterating until the end of the
  // list.
  cout << endl;
  while (temp != nullptr) {
    cout << " Position[" << iterator << "]: " << temp->item << " ";
    temp = temp->next;
    iterator++;
  }
  cout << endl;
}

// Function to delete the entire list
void DeleteList(Node *&head) {
  // The following are necessary variables for the function to work.
  Node *temp = head;
  Node *nextNode;

  // The while loop will iterate up to the end of the list.
  while (temp != nullptr) {
    // nextNode is used to represent and keep tract of the next node in the
    // list. The temp/current node is being deleted.
    nextNode = temp->next;
    delete temp;

    // This updates that the temp/current node is now the next node in the list.
    temp = nextNode;
  }

  // The head is now set to null, meaning the list is empty.
  head = nullptr;
  cout << "The list has been emptied." << endl;
}
