// desing pattern 
// goal of lld writing maintable, extensible code 
// creation design pattern : first we need to create the object 
// structure : how to structure these objects  
// behaviour pattern :  how diffrent object will communitcate with each other 

// prototype desing pattern : as the name suggent the protype 
// which mean we are using this to create our future object 
// we basically need prototype desing pattern when 
// creating a new object is expensive than copying the same object 
// so we baiscally do cloning of the exisiting created object 

// In prototype desing pattern we use deep copy constructor 

// shallow copy constructor : we are just chaging the name of the object both will point to the same memory address
// deep copu  constructor : here we create a new memory address on to which we copy the date from the old memory address 



#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* clone() = 0;
    virtual void display() = 0;
};

class Circle : public Shape {
private:
    int* radius;
public:
    // Constructor
    Circle(int r) {
        radius = new int(r);
    }

    // Copy Constructor (Deep Copy)
    Circle(const Circle& other) {
        radius = new int(*other.radius);  // Deep copy
    }

    // Clone method (Deep Clone)
    Shape* clone() override {
        return new Circle(*this);  // Using the copy constructor for deep copy
    }

    // Display method (Prints the value of radius)
    void display() override {
        cout << "Circle radius = " << *radius << "\n";  // Dereference the pointer to print value
    }

    // Destructor to free dynamically allocated memory
    ~Circle() {
        delete radius;
    }
};

int main() {
    Circle c(5);
    Circle b = c; // Using the copy constructor (Deep Copy)
    cout << "Original Circle: ";
    c.display();
    cout << "Copied Circle: ";
    b.display();

    Shape* x = c.clone(); // Using the clone method (Deep Clone)
    cout << "Cloned Circle: ";
    x->display();

    // Clean up memory
    delete x;
    return 0;
}

