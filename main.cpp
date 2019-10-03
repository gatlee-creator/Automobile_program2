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
    cout << "Car 1: " << endl;
    automobileType car1; 
    car1.setProperties(0, 22, 17.5);
    cout << car1.getInfoString() << endl;
    cout << "drive 25 miles: " << endl;
    car1.drive(25);
    cout << car1.getInfoString() << endl;
    cout << "drive 200 miles: " << endl;
    for(int i = 0; i < 10; i++)
        car1.drive(20);
    cout << car1.getInfoString() << endl;

    cout << "Car 2: " << endl;
    automobileType car2(2500, 19.2, 13.2);
    cout << "drive 450 miles: " << endl;
    car2.drive(450);
    cout << car2.getInfoString() << endl;
    cout << "reset odemeter back to 2500" << endl;
    car2.setProperties(2500, 19.2, 13.2);
    cout << car2.getInfoString() << endl;

    cout << "Car 3: " << endl;
    cout << "odemeter -50 miles" << endl; 
    automobileType car3(-50, 40, 27.8);
    cout << car3.getInfoString() << endl;

    

    return 0;
}