/*
    Name: Graham Atlee
    Course: csc1720
    Date: 10/10/2019
    Location of Program: ~/csc1720/Programs/program2

    This program contains driver code to test the full capabilites of
    the automobileType class. There are 4 automobile objects created that
    each test specific functions of the class. 
*/
#include "automobile.h"
#include <iostream>

using namespace std; 

int main(){

    cout << "CAR 1: created with default constructor values" << endl;
    automobileType car1; 
    cout << car1.getInfoString() << endl;
    cout << "CAR 1: car1 will mainly be testing the setProperties function" << endl;
    cout << "> setting properties with all valid values" << endl;
    car1.setProperties(1000, 18, 25);
    cout << car1.getInfoString() << endl; 
    cout << "> setting an invalid fuel input. No other values should change" << endl;
    car1.setProperties(1200, 25, 30);
    cout << car1.getInfoString() << endl; 
    cout << "> setting all 3 inputs with negative values. "
         << "All 3 error messages should be displayed" << endl;
    car1.setProperties(-1200, -25, -30);
    cout << endl;

    cout << "CAR 2: created parameterized constructor." << endl;
    cout << "A negative efficiency value will be passed in." << endl;
    cout << "Should be set to a default of 30" << endl;
    automobileType car2(2500, 12, -20, 40);
    cout << car2.getInfoString() << endl; 
    cout << "CAR 2: car2 will be testing all of the seperate setFunctions" << endl;
    cout << "> setting fuelLevel to 20." << endl;
    car2.setFuelLevel(20);
    cout << car2.getInfoString() << endl;
    cout << "> setting efficiency to 40." << endl;
    car2.setEfficiency(40);
    cout << car2.getInfoString() << endl;
    cout << "> setting the odemeter to 2400 (below the current value). " 
        <<  "Should get error warning" << endl;
    car2.setOdemeter(2400);
    cout << endl;

    cout << "CAR 3: created with parameterized constructor." << endl;
    automobileType car3(6000, 20, 10, 20); 
    cout << car3.getInfoString() << endl;
    cout << "CAR 3: car3 will mainly be testing the drive and refill functions" << endl;
    cout << "> car3 will drive 150 miles. Odemeter should increase & fuel decrease" << endl; 
    car3.drive(150);
    cout << car3.getInfoString() << endl;
    cout << "> attempting to drive -50 miles. Should get error warning" << endl;
    car3.drive(-50);
    cout << "> refilling the tank with 15 gallons (back to its max capacity)" << endl;
    car3.refillTank(15);
    cout << car3.getInfoString() << endl;
    cout << "> attempting to fill above max capacity. Should get error warning." << endl;
    car3.refillTank(10.5);
    cout << "> driving with less fuel than needed to drive a specified distance (210 miles)." << endl;
    cout << "Odemeter should ONLY increase by actual number of miles driven (200 miles)." << endl;
    cout << "Expected Result: miles = 6350"<< endl;
    car3.drive(210);
    cout << car3.getInfoString() << endl;
    cout << endl;

    cout << "CAR 4: creating car4 with default constructor" << endl;
    automobileType car4; 
    cout << car4.getInfoString() << endl;
    cout << "CAR 4: car4 will soley be testing each of the seperate getFunctions" << endl;
    cout << "calling getOdemeter" << endl;
    cout << car4.getOdemeter() << endl;
    cout << "calling getFuelLevel" << endl;
    cout << car4.getFuelLevel() << endl;
    cout << "calling get efficiency" << endl;
    cout << car4.getEfficiency() << endl;
    cout << endl;

    cout << "End of testing." << endl;

    return 0;
}
