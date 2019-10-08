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
    
    cout << "CAR 1 : all values being set in constructor:" << endl;
    automobileType car(2500, 30, 25.2, 40); 
    cout << car.getInfoString() << endl;

    cout << "CAR 1: Values should not change due to invalid odemeter input" << endl;
    car.setProperties(2400, 30, 25.2); 
    cout << car.getInfoString() << endl; 

    cout << "CAR 2: created with default constructor values" << endl;
    automobileType car2; 
    cout << car2.getInfoString() << endl;

    cout << "CAR 3: created with invalid max fuel below 0. "
         << "Will be defaulted to 20" << endl;
    automobileType car3(3000, 30, 33.3, -33); 

    cout << "CAR 3: changing fuel level above max fuel" << endl;
    car3.setProperties(3000, 25, 33.3);

    cout << "CAR 2: setting the efficieny below 1" << endl;
    car2.setProperties(0, 15, 0);


    return 0;
}