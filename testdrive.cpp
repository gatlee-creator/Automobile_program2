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

    cout << "CAR 2: created parameterized constructor. "
         << "A negative efficiency value will be passed in. "
         << "Should be set to a default of 30" << endl;
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
    cout << "CAR 3: car3 will mainly be testing the drive and refill functions" << endl;
    

    return 0;
}
