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
    automobileType car(2500, 30, 25.2, 40); 

    cout << "All values should be set:" << endl;
    cout << car.getInfoString() << endl;

    cout << "Values should not change due to invalid odemeter input" << endl;
    car.setProperties(2400, 30, 25.2); 
    cout << car.getInfoString() << endl; 

    cout << "Car 2 being created with default values" << endl;
    automobileType car2; 
    cout << car2.getInfoString() << endl;


    return 0;
}