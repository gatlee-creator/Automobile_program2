/*
    Name: Graham Atlee
    Course: csc1720
    Location of Program: ~/csc1720/Labs/lab7

    This program test the full extent of capabilites of the 
    automobileType class. 

*/
#include "automobile.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float temp; 

    cout << "CAR 1 : all values being set in constructor:" << endl;
    automobileType car(2500, 30, 25.2, 40); 
    cout << car.getInfoString() << endl;
    cout << endl;

    cout << "CAR 1: attempting invalid odemeter input & changing fuel" << endl;
    car.setProperties(2400, 25, 25.2); 
    cout << car.getInfoString() << endl; 
    cout << endl;

    cout << "CAR 2: created with default constructor values" << endl;
    automobileType car2; 
    cout << car2.getInfoString() << endl;
    cout << endl;

    cout << "CAR 3: created with invalid max fuel below 0. "
         << "Will be defaulted to 20" << endl;
    automobileType car3(3000, 30, 33.3, -33); 
    cout << car3.getInfoString() << endl;
    cout << endl;

    cout << "CAR 3: changing fuel level above max fuel" << endl;
    car3.setProperties(3000, 25, 33.3); 
    cout << car3.getInfoString() << endl;
    cout << endl;

    cout << "CAR 2: setting the efficieny below 1" << endl;
    car2.setProperties(0, 15, 0);
    cout << endl;

    cout << "CAR 3: setting all to valid values" << endl;
    car3.setProperties(3000, 15, 33.3); 
    cout << car3.getInfoString() << endl; //Efficiency producing 32.29?
    cout << endl;

    cout << "CAR 3: setting the odemeter below 3000" << endl;
    car3.setProperties(2900, 15, 33.3); 
    cout << endl;

    cout << "CAR 3: calling getOdemeter" << endl;
    cout << "Odemeter = " << car3.getOdemeter() << endl; 
    cout << endl;

    cout << "CAR 3: calling getFuel" << endl;
    cout << "Fuel = " << car3.getFuelLevel() << endl;
    cout << endl;

    cout << "CAR 3: calling getEfficiency " << endl;
    cout << "Efficiency = " << car3.getEfficiency() << endl;
    cout << endl;

    cout << "CAR1: driving car1 150 miles " << endl;
    car.drive(150); 
    cout << car.getInfoString() << endl;

    cout << "CAR1: refilling with gas +20" << endl;
    car.refillTank(20);
    cout << car.getInfoString() << endl;
    cout << endl;

    cout << "CAR2: attempting to refill pass its max capacity of 20" << endl;
    car2.refillTank(20);
    cout << endl;

    cout << "CAR4: created car4 with a fuel range of 12 miles" << endl;
    automobileType car4(1000, 6, 2, 10); 
    cout << "CAR4: drives 13 miles (outside of its fuel range) "
         << "Odemeter should ONLY increase by 12 miles" << endl;
    car4.drive(13);
    cout << car4.getInfoString() << endl; 

    return 0;
}