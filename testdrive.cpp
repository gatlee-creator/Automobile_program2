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

    return 0;
}
