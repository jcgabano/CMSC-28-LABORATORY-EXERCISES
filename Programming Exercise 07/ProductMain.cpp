#include "ProductInventory.h" // include the external header file
#include <string>
#include <iostream>

using namespace std;

int main() {
  
  // Print program information
  cout << "This program manages a store's products through class inheritance and encapsulation." << endl;
  cout << "\nProgrammed by: Jodi C. Gabano\n" << endl;
  cout << "=======================================" << endl;

  // Clothing details
  cout << "\nEnter details for a Clothing item:" << endl;
  Clothing clothing1; // create an instance of the clothing class
  clothing1.input(); // call the input function to get user input
  

  // Electronics details
  cout << "\nEnter details for an Electronics item:" << endl;
  Electronics electronics1; // create an instance of the electronics class
  electronics1.input(); // call the input function to get user input

  // Displaying all the details of each product using the getter methods
  cout << "\n---------------------------------------\n" << endl;
  cout << "Clothing Item:" << endl;
  cout << "Name: " << clothing1.getName() << endl;
  cout << "Brand: " << clothing1.getBrand() << endl;
  cout << "Price: $" << clothing1.getPrice() << endl;
  cout << "Quantity: " << clothing1.getQuantity() << endl;
  cout << "Description: " << clothing1.getDescription() << endl;
  cout << "Category: " << clothing1.getCategory() << endl;
  cout << "Model: " << clothing1.getModel() << endl;
  cout << "Size: " << clothing1.getSize() << endl;
  cout << "Color: " << clothing1.getColor() << endl;
  cout << "Maerial: " << clothing1.getMaterial() << endl;

  cout << "\nElectronics Item:" << endl;
  cout << "Name: " << electronics1.getName() << endl;
  cout << "Brand: " << electronics1.getBrand() << endl;
  cout << "Price: $" << electronics1.getPrice() << endl;
  cout << "Quantity: " << electronics1.getQuantity() << endl;
  cout << "Description: " << electronics1.getDescription() << endl;
  cout << "Category: " << electronics1.getCategory() << endl;
  cout << "Model: " << electronics1.getModel() << endl;
  cout << "Warranty: " << electronics1.getWarranty() << " years" << endl;
  cout << "Technical Specifications: " << electronics1.getTechnicalSpecifications() << endl;

  return 0;
}