#include<bits/stdc++.h>
using namespace std;

// desing pattern 
// goal of lld writing maintable, extensible code 
// creation design pattern : first we need to create the object 
// structure : how to structure these objects  
// behaviour pattern :  how diffrent object will communitcate with each other 

// builder design pattern:
// it is used to construct complex object step by step 


class Car{
public: 
    string modelName;
    string engineType;
    string clr;

    void showDetails() {
        cout<<"Model Name :"<<modelName<<"\n";
        cout<<"Engine Type :"<<engineType<<"\n";
        cout<<"Car Colour :"<<clr<<"\n";
    }
};

// virtual function mean we can override the function in the child class 
// pureVirtual function is which does not contain the implementation 
// whichever class will drive the abstract class must add the implementation of pure virtual function

class CarBuilder{
public:
    virtual ~CarBuilder() = default;
    virtual Car* GetCar() = 0;
    virtual void setModel(string s) = 0;
    virtual void setEngine(string s) = 0;
    virtual void setClr(string s) = 0;
};


class SportsCarBuilder : public CarBuilder{
    private:
        Car* car;
    public:
        void setModel(string s) override{
            car->modelName = s;
        }
        void setEngine(string s)override{
            car->engineType = s;
        }
        void setClr(string s) override{
            car->clr = s;
        }
        Car* GetCar() override{
            return car = new Car();
        }
};


class CarDirector{
private:
    CarBuilder  *builder;
    Car *c;
public:
    CarDirector(CarBuilder*b){
        builder = b;
    }
    void ConstructCar(){
        c = builder->GetCar();
        builder->setModel("ferrari");
        builder->setEngine("440hp");
        builder->setClr("red");
    }
    void showCar(){
        c->showDetails();
    }


};


int main(){
    SportsCarBuilder *b = new SportsCarBuilder();
    CarDirector * d = new CarDirector(b);
    d->ConstructCar();
    d->showCar();
    return 0;
}