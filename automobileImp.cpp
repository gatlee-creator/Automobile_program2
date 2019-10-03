/*
    Implementation of the automobileType class. Contains member variables
    and member functions for the automobileType. 
*/
#include "automobile.h"
#include <string>

using namespace std;

void automobileType::setProperties(float odmtrToSet, float fuelToSet, float effoToSet){
    const int minThres = 0; 
      //check if all 3 are less than 0. If not then we set them to param value 
    odmtrToSet < minThres ? odemeter=0 : odemeter=odmtrToSet; 
    fuelToSet < minThres ? fuel=0 : fuel=fuelToSet; 
    effoToSet < minThres ? efficiency=0 : efficiency=effoToSet;
}

string automobileType::getInfoString() const{
    string automobileStatus; 
    string fuelToString, odmtrToString, effoToString;
    int pos; 

      //convert int members to strings
    odmtrToString = to_string((int)odemeter);
    fuelToString = to_string(fuel); 
    effoToString = to_string(efficiency);

    //now we want to modify strings length to show 2 decimal places
    pos = fuelToString.find_first_of(".");
    fuelToString = fuelToString.erase(pos + 3, fuelToString.length()); 

    pos = effoToString.find_first_of(".");
    effoToString = effoToString.erase(pos + 3, effoToString.length());
    

      //concat those strings into a larger string
    automobileStatus = "Miles = " + odmtrToString +     " " + 
                       "Fuel = "  + fuelToString +  " " +
                       "Efficiency = " + effoToString; 

    return automobileStatus;
}

void automobileType::drive(float milesTrav){
    float gallonsUsed;

      //first do a 0 miles check
    if(milesTrav <= 0)
        return; 
    
     //do a formula to figure how many gallons we used 
     gallonsUsed = (1 / efficiency) * milesTrav; 

      //if the fuel level goes below 0 then we're out of gas 
    if((fuel - gallonsUsed) <= 0)
        fuel = 0;
    else
        fuel -= gallonsUsed; //subtract gallons used from our fuel

    odemeter += milesTrav; //add this vechile has traveled to the odemeter
 
}

//default constructor
automobileType::automobileType(){
  odemeter = 0;
  fuel = 0;
  efficiency = 0;
}

//constructor that takes params 
automobileType::automobileType(float odmtrToSet, float fuelToSet, float effoToSet){
  setProperties(odmtrToSet, fuelToSet, effoToSet);
}