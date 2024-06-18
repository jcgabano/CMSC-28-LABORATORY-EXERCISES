// Include guards prevent the contents of the header file from being included more than once in the same compilation unit.
#ifndef PRODUCTINVENTORY_H
#define PRODUCTINVENTORY_H

#include <iostream>
#include <string>

using namespace std;

// Parent class Product
class Product {
private:
    // Defining private attributes
    string name;
    string brand;
    double price;
    int quantity;
    string description;
    string category;
    string model;

public:
    // Defining Constructors
    Product() : price(0.0), quantity(0) {}  // Default constructor initializes price and quantity to 0

    // Parameterized constructor
    Product(string name, string brand, double price, int quantity,
            string description, string category, string model)
            : name(name), brand(brand), price(price), quantity(quantity),
              description(description), category(category), model(model) {}

    // Getter and Setter methods for each attribute
    // 'this->' is used to explicitly refer to the member variables of the class. This helps to differentiate between the local variable and the class member with the same name.

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }
    string getBrand() {
        return brand;
    }

    // Setter for price with error trapping
    void setPrice(double price) {
        if (price >= 0) {
            this->price = price;
        } else {
            cout << "Invalid price! Price cannot be negative. Terminating program." << endl;
            exit(EXIT_FAILURE);
        }
    }
    double getPrice() {
        return price;
    }

    // Setter for quantity with error trapping
    void setQuantity(int quantity) {
        if (quantity >= 0) {
            this->quantity = quantity;
        } else {
            cout << "Invalid quantity! Quantity cannot be negative. Terminating program." << endl;
            exit(EXIT_FAILURE);
        }
    }
    int getQuantity() {
        return quantity;
    }

    void setDescription(string description) {
        this->description = description;
    }
    string getDescription() {
        return description;
    }

    void setCategory(string category) {
        this->category = category;
    }
    string getCategory() {
        return category;
    }

    void setModel(string model) {
        this->model = model;
    }
    string getModel() {
        return model;
    }

    // Method to accept user input for the common attributes
    void input() {
        cout << "Enter product name: ";
        getline(cin, name);
        cout << "Enter brand: ";
        getline(cin, brand);
        cout << "Enter price: ";
        cin >> price;
        setPrice(price);  // Validate input
        cout << "Enter quantity: ";
        cin >> quantity;
        setQuantity(quantity);  // Validate input
        cin.ignore();  // To ignore the newline character left by cin
        cout << "Enter description: ";
        getline(cin, description);
        cout << "Enter category: ";
        getline(cin, category);
        cout << "Enter model: ";
        getline(cin, model);
    }
};

// Derived class Clothing with unique attributes and inherited attributes from class Product
class Clothing : public Product {
// Defining provate attributes
private:
    string size;
    string color;
    string material;

public:
    // Defining Constructors
    Clothing() : Product() {}  // Default constructor

    // Parameterized constructor
    Clothing(string name, string brand, double price, int quantity,
             string description, string category, string model,
             string size, string color, string material)
             : Product(name, brand, price, quantity, description, category, model),
               size(size), color(color), material(material) {}

    // Getter and Setter methods for each attribute
    void setSize(string size) {
        this->size = size;
    }
    string getSize() {
        return size;
    }

    void setColor(string color) {
        this->color = color;
    }
    string getColor() {
        return color;
    }

    void setMaterial(string material) {
        this->material = material;
    }
    string getMaterial() {
        return material;
    }

    // Method to accept user input for both common and specific attributes
    void input() {
        Product::input();  // Call Product class method to input common attributes
        cout << "Enter size: ";
        getline(cin, size);
        cout << "Enter color: ";
        getline(cin, color);
        cout << "Enter material: ";
        getline(cin, material);
    }
};

// Derived class Electronics with unique attributes and inherited attributes from class product
class Electronics : public Product {
// Defining private attributes
private:
    double warranty; // warranty in years
    string technicalSpecifications;

public:
    // Defining Constructors
    Electronics() : Product(), warranty(0.0) {}  // Default constructor

    // Parameterized constructor
    Electronics(string name, string brand, double price, int quantity,
                string description, string category, string model,
                double warranty, string technicalSpecifications)
                : Product(name, brand, price, quantity, description, category, model), warranty(warranty), technicalSpecifications(technicalSpecifications) {}

    // Getter and Setter methods for each attribute
    // Setter for warranty with error trapping
    void setWarranty(double warranty) {
        if (warranty >= 0) {
            this->warranty = warranty;
        } else {
            cout << "Invalid warranty! Warranty cannot be negative. Terminating program." << endl;
            exit(EXIT_FAILURE);
        }
    }
    double getWarranty() {
        return warranty;
    }

    void setTechnicalSpecifications(string technicalSpecifications) {
        this->technicalSpecifications = technicalSpecifications;
    }
    string getTechnicalSpecifications() {
        return technicalSpecifications;
    }

    // Method to accept user input for both common and specific attributes
    void input() {
        Product::input();  // Call Product class method to input common attributes
        cout << "Enter warranty (in years, e.g., 0.5 for 6 months): ";
        cin >> warranty;
        setWarranty(warranty);  // Validate input
        cin.ignore();  // To ignore the newline character left by cin
        cout << "Enter technical specifications: ";
        getline(cin, technicalSpecifications);
    }
};

#endif // PRODUCTINVENTORY_H