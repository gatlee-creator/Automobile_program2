#include "automobile.h"
#include <iostream>

using namespace std; 

int main(){

    cout << "CAR1: creating car1 with parameterized constructor." << endl;
    automobileType car1(12000, 21, 20.5, 25);
    cout << car1.getInfoString() << endl;
    cout << "CAR1: calling setProperties and passing an invalid fuelInput."
         <<  "No other values should be" << endl;
    car1.setProperties(13050, 27, 30.5); 

    

    return 0;
}
