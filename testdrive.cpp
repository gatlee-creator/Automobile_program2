#include "automobile.h"
#include <iostream>

using namespace std; 

int main(){

    cout << "CAR1: creating car1 with parameterized constructor." << endl;
    automobileType car1(12000, 21, 20.5, 25);
    cout << car1.getInfoString() << endl;
    cout << "driving 30 miles" << endl;
    car1.drive(30);
    cout << car1.getInfoString() << endl;

    return 0;
}
