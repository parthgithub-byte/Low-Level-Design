#include <iostream>
#include <string>

using namespace std;

// Encapsulation
/*
Encapsulation is about data security. While the Abstraction was about data hiding (for convenience), Encapsulation talks about what internals can the user even know or modify from the system. The user cannot access these details directly as they are "encapsulated". It is like in a car, a driver not havng the brake pedal and straight up using the lever or cable, but that was solved by Abstraction. Encapsulation is more like, the limiters set by the company for an engine component sealed/ locked so that user cannot modify them from outside.

For these things, Encapsulation uses two concepts:
1) Access Specifiers:
Specify the type of access for different data members. There are 3 types:

i)    private access specifier: Data in it is not accessible out of the class
ii)   public access specifier: Data here (mostly behaviours/ methods) is accessible from anywhere. 
iii)  protected access specifer. More on it in the topic of Inheritance.

2) getters and setters:
Special methods used to specifically get or set the data member values. All the data members are usually private. So, getters and setters are widely used to get and set the necessary ones from them.
Why use getters:
    - Only certain data members to be made accesible. 
    - Format the output when giving out the data members
Why use setters:
    - Only certain data members can be modified
    - Add validations constraints before modifications

*/

class SportsCar{
// private access specifier:
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;


// public access specifier:
public:
    // above are all the data members, specific to the child class
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyre = "Default";
    }
    
    // getters and setters:

    int getSpeed(){
        return currentSpeed;
    }

    void setSpeed(int val){
        // validations first
        if (!isEngineOn){
            cout<<brand<<" "<<model<<" : Engine is off! Cannot set the speed."<<endl;
            return;
        }
        if (val > 200){
            cout<<brand<<" "<<model<<" : Speed limit crossed! Cannot set the speed."<<endl;
            return;
        }
        currentSpeed = val;
        cout<<brand<<" "<<model<<" : Car speed set to "<<currentSpeed<<endl;
    }

    void getTyre(){
        // output formatting wherever necessary
        cout<<brand<<" "<<model<<" : Car tyres of brand : "<<tyre<<endl;
    }

    void setTyre(string tyreName){
        // any validations needed, like checking if the brand of tyre even exists and suitable
        tyre = tyreName;
        cout<<brand<<" "<<model<<" : Car tyres set to : "<<tyre<<endl;
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
    SportsCar *myCar = new SportsCar("Lamborghini", "Revuelto");
    // We can initiate the parent class using the child class. More on this in the Dynamic Polymorphism topic.
    cout<<"Your current speed is: "<<myCar->getSpeed()<<endl;
    myCar->setSpeed(50);
    // error message

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    cout<<"Your current speed is: "<<myCar->getSpeed()<<endl;
    myCar->setSpeed(500);
    //error message
    myCar->setSpeed(50);

    myCar->shiftGear(3);
    myCar->accelerate();
    myCar->brake();

    myCar->getTyre();
    myCar->setTyre("MRF");
    myCar->getTyre();

    myCar->stopEngine();
    
    delete myCar;

    return 0;
}


/*
Output:
Your current speed is: 0
Lamborghini Revuelto : Engine is off! Cannot set the speed.
Car is started.
Lamborghini Revuelto : Gear is shifted to gear : 1
Lamborghini Revuelto : Car speed to be accelerated. Current car speed is : 0 km/h
Lamborghini Revuelto : Car speed accelerated. Now the car speed is : 20 km/h
Your current speed is: 20
Lamborghini Revuelto : Speed limit crossed! Cannot set the speed.
Lamborghini Revuelto : Car speed set to 50
Lamborghini Revuelto : Gear is shifted to gear : 3
Lamborghini Revuelto : Car speed to be accelerated. Current car speed is : 50 km/h
Lamborghini Revuelto : Car speed accelerated. Now the car speed is : 70 km/h
Lamborghini Revuelto : Car is braking! Now the car speed is : 50 km/h
Lamborghini Revuelto : Car tyres of brand : Default
Lamborghini Revuelto : Car tyres set to : MRF
Lamborghini Revuelto : Car tyres of brand : MRF
Lamborghini Revuelto : Car engine stopped!
Turn it on to use the car again.
*/