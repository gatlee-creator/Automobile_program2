/*
    Implementation of the automobileType class. Contains member variables
    and member functions for the automobileType. 
*/
#include "automobile.h"
#include <string>
#include <iostream>

using namespace std;

void automobileType::setProperties(float odmtrInput, float fuelInput, float effoInput){
  //lets do a cascade of condtions to make sure we have valid values. 

    //check the fuel input 
  if((fuelInput > maxFuel) || (fuelInput < 0)){
    cerr << "Invalid fuel input" << endl;
    return; //exit the function 
  }
  else if(effoInput < 1){ //check efficieny input
    cerr << "Invalid efficiency input" << endl;
    return; 
  }
  else if((odmtrInput < odemeter) || (odmtrInput < 0)){ //check odemeter 
    cerr << "Invalid odemeter input" << endl;
    return; 
  }
  else{ //if all are valid then we can set them 
    fuel = fuelInput;
    efficiency = effoInput; 
    odemeter = odmtrInput; 
  }

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
  odemeter = DEFAULT_ODEMETER;
  fuel = DEFAULT_FUEL_LEVEL;
  efficiency = DEFAULT_EFFICIENY;
  maxFuel = DEFAULT_MAX_FUEL; 
}

//constructor that takes params 
automobileType::automobileType(float odmtrInput, float fuelInput, float effoInput, float maxFuelInput){
  //first we want to set the maxFuel && do prelimary check
  if(maxFuelInput > 0){
    maxFuel = maxFuelInput;
  } else {
    maxFuel = DEFAULT_MAX_FUEL; 
  }

  //now we can call setproperties 
  setProperties(odmtrInput, fuelInput, effoInput);


}