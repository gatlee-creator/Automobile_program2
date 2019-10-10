/*
    Implementation of the automobileType class. Contains member variables
    and member functions for the automobileType. 
*/
#include "automobile.h"
#include <string>
#include <iostream>

using namespace std;

int automobileType::setFuelLevel(float fuelInput){
  //check the fuel input 
  if((fuelInput > maxFuel) || (fuelInput < 0)){
    //make sure to state range of acceptable values
    cerr << "Error: Invalid fuel input. Permitted Range: 0-" << maxFuel << endl;
    fuel = DEFAULT_FUEL_LEVEL; 
    cerr << "RES: Fuel level set to 15 by default. " << endl;
    // cerr << "No other values have been set." << endl; 
    return -1; //exit the function 
  } else{
    fuel = fuelInput; 
    return 0; 
  }
}

int automobileType::setEfficiency(float effoInput){
  if(effoInput < 1){ //check efficieny input
    cerr << "Error: Invalid efficiency input. Permitted Range: > 1" << endl;
    efficiency = DEFAULT_EFFICIENY; 
    cerr << "RES: Efficiency set to 30 by default."<< endl; 
    // cerr << " No other values have been set." << endl; 
    return -1; 
  } else {
    efficiency = effoInput;
    return 0;  
  }
}

int automobileType::setOdemeter(float odmtrInput){
  if((odmtrInput < odemeter) || (odmtrInput < 0)){ //check odemeter 
    cerr << "Error: Invalid odemeter input. Permitted range: > 0 or > current odemeter" << endl;
    odemeter = DEFAULT_ODEMETER;
    cerr << "RES: Odemeter set to 0 by default."<< endl;
    // cerr << " No other values have been set." << endl; 
    return -1; 
  }
  else{ 
    odemeter = odmtrInput; 
    return 0; 
  }
}

void automobileType::setProperties(float odmtrInput, float fuelInput, float effoInput){
  setOdemeter(odmtrInput);
  setFuelLevel(fuelInput);
  setEfficiency(effoInput);
}

string automobileType::getInfoString() const{
    string automobileStatus; 
    string fuelToString, odmtrToString, effoToString, maxToString; 
    int pos; 

      //convert int members to strings
    odmtrToString = to_string((int)odemeter);
    fuelToString = to_string(fuel); 
    effoToString = to_string(efficiency);
    maxToString = to_string(maxFuel);

    //now we want to modify strings length to show 2 decimal places
    pos = fuelToString.find_first_of(".");
    fuelToString = fuelToString.erase(pos + 3, fuelToString.length()); 

    pos = effoToString.find_first_of(".");
    effoToString = effoToString.erase(pos + 3, effoToString.length());

    pos = maxToString.find_first_of(".");
    maxToString = maxToString.erase(pos + 3, maxToString.length());
    

      //concat those strings into a larger string
    automobileStatus = "Miles = " + odmtrToString + " " + 
                       "Fuel = "  + fuelToString +  " " +
                       "Efficiency = " + effoToString + " " +
                       "Max Capacity = " + maxToString; 

    return automobileStatus;
}

float automobileType::getOdemeter(){
  return odemeter; 
}

float automobileType::getFuelLevel(){
  return fuel;
}

float automobileType::getEfficiency(){
  return efficiency; 
}

void automobileType::refillTank(float fuelInput){
  if(fuelInput > maxFuel){
    cerr << "Invalid fuel input" << endl;
    return;
  }
  else{
    fuel = fuelInput; 
  }
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
    cerr << "Error: Invalid max fuel value" << endl;
    maxFuel = DEFAULT_MAX_FUEL; 
    cerr << "RES: Max fuel set to 20 by default" << endl; 
  }

  //now we can call setproperties 
  setProperties(odmtrInput, fuelInput, effoInput);


}