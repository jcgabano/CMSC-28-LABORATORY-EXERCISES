/*  PE03 - Queue Implementation
    Written by: Jodi Gabano
    Date: April 8, 2024  */

#include <iostream>
#include <string>
#include <iomanip> // for setprecision on decimal places, upto 4 decimal places.

using namespace std;

// Struct to represent a node in the queue
struct Node {
    string name; // represents the customers name
    float totalAmount; // represents the total amount payable
    Node* next;
};

// Queue class (similar to a struct)
class Queue {
private:
    Node* front; // initalize the front of the queue
    Node* rear; // initialize the rear of the queue

public:
    // Constructor for the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to create and return an empty queue
    static Queue* INIT() {
        return new Queue();
    }

    // Function to check if the queue is empty
    bool EMPTY() {
        return front == nullptr;
    }

    // Function to return a copy of the front node of the queue
    Node* FRONT() {
        return front;
    }

    // Function to insert (enqueue) customer info into the queue
    void ENQUEUE(const string &name, float totalAmount) {
        // creates a new node for the info to be inserted into
        Node* newNode = new Node();
        newNode->name = name;
        newNode->totalAmount = totalAmount;
        newNode->next = nullptr;
        // if the empty function is true, then the new node is the front and rear
        if (EMPTY()) {
            front = rear = newNode;
        // if the empty function is false, then the new node is added to the rear
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove and return the front node of the queue
    Node* DEQUEUE() {
        // if the empty function is true, then the queue is empty and no nodes can be removed
        if (EMPTY()) {
            return nullptr;
        }
        // creating a temporary node to store the front node
        Node* temp = front;
        // if the front and rear are the same, then the queue is empty after the front node is removed
        if (front == rear) {
            front = rear = nullptr;
        // if the front is not the rear, then the front is moved to the next node
        } else {
            front = front->next;
        }
        // return the front node (the node that was dequeued)
        return temp; 
    }
};

int main() {
    // Static member function of the Queue class. Creates a new and empty queue.
    Queue* Q = Queue::INIT();

    cout << "Jodi's Bakeshop - Counter 1:" << endl;
  
    int choice;
    // do-while loop is used to continue the program until the user chooses to exit
    do {
        // displaying the menu
        cout << "\n[1] Fall in line\n[2] Serve Customer\n[3] Next Customer\n[4] Closing Time\n[0] Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        // switch statement to handle the user's choice
        switch (choice) {
            // first case is to add a customer to the queue (enqueue)
            case 1: {
                string name;
                float totalAmount;
                // get the name and total amount of the customer and add it to the queue
                cout << "\nEnter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Total Amount of Items: ";
                cin >> totalAmount;
                Q->ENQUEUE(name, totalAmount);
                break;
            }
            // second case is to serve the customer at the front of the queue (dequeue)
            case 2: {
                // create a node pointer that points to the front node and performs the dequeue function
                Node* servedNode = Q->DEQUEUE();
                // if the node is not the rear node then perform the dequeue function
                if (servedNode != nullptr) {
                    cout << "\nNow serving " << servedNode->name << " with total amount payable of " << fixed << setprecision(4) << servedNode->totalAmount << endl;
                    delete servedNode; // free memory for the served customer
                // if the node is the rear node then the queue is empty
                } else {
                    cout << "\nThe QUEUE is EMPTY. No orders to serve." << endl;
                }
                break;
            }
            // third case is to show the next customer in the queue
            case 3: {
                // create a node pointer that points to the front node and performs the front function
                Node* nextNode = Q->FRONT();
                // if the node is not the rear node then perform the front function
                if (nextNode != nullptr) {
                    cout << "\nNext order: For " << nextNode->name << " with total amount payable of " << fixed << setprecision(4) << nextNode->totalAmount << endl;
                // if the node is the rear node then the queue is empty
                } else {
                    cout << "\nThe QUEUE is EMPTY. No order to serve." << endl;
                }
                break;
            }
          // fourth case is to serve (dequeue) the remaining customers in the queue
          case 4: {
              cout << "\nClosing Time: " << endl;
              // if the empty function for Q returns true then the queue is empty
              if (Q->EMPTY()) {
                  cout << "The QUEUE is EMPTY. No customer/s to serve." << endl;
              // if the empty function for Q returns false then the queue is not empty and the function continues
              } else {
                  // loop will go through the remaining nodes in the queue until it is empty
                  while (!Q->EMPTY()) {
                      // same process as case 2 with a node pointer
                      Node* servedNode = Q->DEQUEUE();
                          cout << "Now serving " << servedNode->name << " with total amount payable of " << fixed << setprecision(4) << servedNode->totalAmount << endl;
                          delete servedNode; // Free memory for the served customer
                  }
                  // Once the loop is finished, the queue is empty and all customers have been served
                  cout << "All customers have been served." << endl;
              }
              break;
          }

            // case 0 is to exit the program
            case 0: {
                cout << "\nExiting the checkout system. Thanks for shopping at Jodi's Bakeshop!" << endl;
                break;
            }
            // check if the user entered an invalid choice and display the menu again
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 0); // loop terminates once the user's choice is 0

    delete Q; // Freeing the memory allocated for the queue

    return 0;
}
