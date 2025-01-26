// here is the example of shallow copy constructor 
// Until there is no reference datatpe like pointer etc 
// shallow copy and deep copy will behave same 

// but if they have the pointer member variable then 
// the functionliy of both the object will change 
// #include<bits/stdc++.h>
// using namespace std;

// class circle{
// public:
//   int radius;
//   void setRadius(int r){
//       radius = r;
//   }
//   void printr(){
//       cout<<radius<<"\n";
//   }
// };

// int main(){
//     circle c;
//     c.setRadius(2);
//     c.printr();
//     circle b = c;
//     c.setRadius(3);
//     c.printr();
//     b.printr();
//     return 0;
// }




/*

#include <iostream>
#include <cstring>

class Car {
private:
    std::string* make;
    std::string* model;

public:
    // Constructor
    Car(const std::string& make, const std::string& model) {
        this->make = new std::string(make);  // Dynamically allocated memory
        this->model = new std::string(model); // Dynamically allocated memory
    }

    // Shallow copy constructor
    Car(const Car& other) {
        make = other.make;  // Shallow copy: simply copy the pointer
        model = other.model; // Shallow copy: simply copy the pointer
        std::cout << "Shallow copy constructor called" << std::endl;
    }

    // Deep copy constructor
    Car(const Car& other, bool deepCopy) {
        if (deepCopy) {
            // Deep copy: allocate new memory and copy the contents
            make = new std::string(*other.make);
            model = new std::string(*other.model);
            std::cout << "Deep copy constructor called" << std::endl;
        } else {
            // Shallow copy
            make = other.make;
            model = other.model;
        }
    }

    // Destructor to free the allocated memory
    ~Car() {
        delete make;
        delete model;
    }

    // Display method to show the car details
    void display() const {
        std::cout << "Car Make: " << *make << ", Model: " << *model << std::endl;
    }

    // Method to modify the make (just for testing the shallow copy)
    void setMake(const std::string& newMake) {
        *make = newMake;
    }
};

int main() {
    // Original car object
    Car car1("Toyota", "Corolla");
    std::cout << "Original car1: ";
    car1.display();

    // Shallow copy of car1
    Car car2 = car1;  // Uses shallow copy constructor
    std::cout << "Shallow copy car2: ";
    car2.display();

    // Modify car2's make
    car2.setMake("Honda");

    std::cout << "\nAfter modifying car2:" << std::endl;
    std::cout << "Original car1: ";
    car1.display();  // This will also change because of shallow copy
    std::cout << "Shallow copy car2: ";
    car2.display();

    // Deep copy of car1
    Car car3(car1, true);  // Uses deep copy constructor
    std::cout << "\nDeep copy car3: ";
    car3.display();

    // Modify car3's make (this won't affect car1)
    car3.setMake("Ford");

    std::cout << "\nAfter modifying car3:" << std::endl;
    std::cout << "Original car1: ";
    car1.display();  // car1 remains unchanged
    std::cout << "Deep copy car3: ";
    car3.display();  // car3 is independent

    return 0;
}

*/