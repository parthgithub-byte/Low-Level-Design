#include <iostream>
#include <string>

using namespace std;

// Abstract Class
/*
An abstract class in C++ is a class that has atleast one function which is not defined, but only declared (pure virtual function). Such classes act as classes for contract rather than instantiation. Thus, we cannot make instance of such a class. 
Virtual functions need to be overridden by the child classes. Thus, we can instantiate the parent class only through the child class later.

(
Trivia:
If a class has all the functions purely virtual, it is referred mostly as purely abstract class or purely virtual class. This is similar to Interface in Java, though in Java, even data members are not allowed for the base class, C++ poses no such restriction.


Purely virtual vs Virtual Functions:
Purely Virtual Functions: Only declared as ( = 0). Not defined. Also they must be overriden in the child classes.

Virtual functions have no such restrictions. They are mostly defined in the base class and there is a choice to override or not them as per individual child class. Significance of these will later come in the topic: Runtime Polymorphism later.
)
*/
class Car{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {};  
    // deconstructor called, this does not require any implementation, thus overriding is not a compulsion. Hence, not a purely virtual function.
};


// Concrete Class: Actual implementation
class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    // above are all the data members, specific to the child class
    SportsCar(string b, string m){
        this->brand = b;
        this->model = b;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<"Car is started."<<endl;
    }

    void shiftGear(int gear){
        if (!isEngineOn){
            cout<<brand<<" "<<model<<" : Engine is off! Cannot shift the gear."<<endl;
            return;
        }

        currentGear = gear;
        cout<<brand<<" "<<model<<" : Gear is shifted to gear : "<<currentGear<<endl;
    }

    void accelerate(){
        if (!isEngineOn){
            cout<<brand<<" "<<model<<" : Engine is off! Cannot shift the gear."<<endl;
            return;
        }
        cout<<brand<<" "<<model<<" : Car speed to be accelerated. Current car speed is : "<<currentSpeed<<" km/h"<<endl;
        currentSpeed += 20;
        cout<<brand<<" "<<model<<" : Car speed accelerated. Now the car speed is : "<<currentSpeed<<" km/h"<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        currentSpeed = max(0, currentSpeed); // minimum speed can go down to 0 only, zeroing if above subtraction made it negative
        cout<<brand<<" "<<model<<" : Car is braking! Now the car speed is : "<<currentSpeed<<" km/h"<<endl;

    }

    void stopEngine(){
        isEngineOn = 0;
        currentSpeed = 0;
        currentGear = 0;
        cout<<brand<<" "<<model<<" : Car engine stopped!"<<endl<<"Turn it on to use the car again."<<endl;
    }
};



int main(){
    Car *myCar = new SportsCar("Lamborghini", "Revuelto");
    // We can initiate the parent class using the child class. More on this in the Dynamic Polymorphism topic.
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(3);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    
    delete myCar;

    return 0;
}


/*
Output:
Car is started.
Lamborghini Lamborghini : Gear is shifted to gear : 1
Lamborghini Lamborghini : Car speed to be accelerated. Current car speed is : 0 km/h
Lamborghini Lamborghini : Car speed accelerated. Now the car speed is : 20 km/h
Lamborghini Lamborghini : Gear is shifted to gear : 3
Lamborghini Lamborghini : Car speed to be accelerated. Current car speed is : 20 km/h
Lamborghini Lamborghini : Car speed accelerated. Now the car speed is : 40 km/h
Lamborghini Lamborghini : Car is braking! Now the car speed is : 20 km/h
Lamborghini Lamborghini : Car engine stopped!
Turn it on to use the car again.
*/