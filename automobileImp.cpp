/*

    Name: Graham Atlee
    Course: csc1720
    Date: 10/10/2019
    Location of Program: ~/csc1720/Programs/program2

    Implementation of the automobileType class. Contains mostly 
    defenitions for the automobileType. Above each defenition is a brief
    description of the function.

    Note: may see this warning upon compiling 
      warning: in-class initialization of non-static data member is a C++11 extension
*/

#include "automobile.h"
#include <string>
#include <iostream>

using namespace std;

/*
  Function takes a float parameter and uses it to set the fuel
  Pre Condition:
    fuelInput >= 0 or fuelInput < maxFuel
*/
int automobileType::setFuelLevel(float fuelInput){
   //check if fuel input is in acceptable values
  if((fuelInput > maxFuel) || (fuelInput < 0)){
    cerr << "Error: Invalid fuel input. Permitted Range: 0-" << maxFuel << endl;
    return -1; //exit the function 
  } 
  else{
    fuel = fuelInput; //set fuel
    return 0; //all good
  }
}

/*
  Function takes a float parameter and uses it to set the efficiency
  Pre Condition:
    effoInput > 1
*/
int automobileType::setEfficiency(float effoInput){
  //check efficiency input is in range of acceptable values
  if(effoInput < 1){ 
    cerr << "Error: Invalid efficiency input. Permitted Range: > 1" << endl;
    return -1; 
  } 
  else {
    efficiency = effoInput;
    return 0;  
  }
}
/*
  Function takes a float parameter and uses it to the set the odemeter 
  Pre Condition:
    odmtrInput > 0 or odmtrInput > odemeter 
*/
int automobileType::setOdemeter(float odmtrInput){
  //check odemeter input is in range of acceptable values 
  if((odmtrInput < odemeter) || (odmtrInput < 0)){ 
    cerr << "Error: Invalid odemeter input. Permitted range: > 0 or > current odemeter" << endl;
    return -1; 
  }
  else{ 
    odemeter = odmtrInput; 
    return 0; 
  }
}

/*
  Function takes 3 float parameters to set odemeter, fuel, efficiency.
  Pre Condition:
    odmtrInput > 0 or odmtrInput > odemeter 
    fuelInput >= 0 or fuelInput < maxFuel
    effoInput > 1
*/
void automobileType::setProperties(float odmtrInput, float fuelInput, float effoInput){
  int FLAGS[3];
  const int INVALID = -1; 

   //use a small cascade of conditonals to check if valid inputs
  if(odmtrInput < odemeter){
    FLAGS[0] = INVALID;
    cerr << "Error: invalid odemeter input. "
         << "Permitted range: >= 0 or < current odemeter" << endl;
  }
  if((fuelInput > maxFuel) || (fuelInput < 0)){
    FLAGS[1] = INVALID; 
    cerr << "Error: invalid fuel input. " 
         << "Permitted range: >= 0 or < " << maxFuel << endl;
  }
  if(effoInput < 1){
    FLAGS[2] = INVALID;
    cerr << "Error: invalid efficiency input. "
         << "Permitted range: > 0" << endl;
  }

   //if none are valid then none will be set 
  if((FLAGS[0] == INVALID) || (FLAGS[1] == INVALID) || (FLAGS[2] == INVALID)){
    cerr << "Res: No other values have been set" << endl;
    return; 
  } else { //if all are valid then we can set them
    odemeter = odmtrInput;
    fuel = fuelInput;
    efficiency = effoInput;
  }

}

/*
  Function returns a string showing current values 
  of odemeter, fuel, and efficiency
*/
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

//Function accesses and returns the odemeter value
float automobileType::getOdemeter(){
  return odemeter; 
}

//Function accesses and returns the fuel value
float automobileType::getFuelLevel(){
  return fuel;
}

//Function accesses and returns the efficiency value
float automobileType::getEfficiency(){
  return efficiency; 
}

/*
  Function to refill fuel by adding fuel and fuelInput together.
  Pre Condition:
    fuelInput > 0 or fuelInput < maxFuel 
*/
void automobileType::refillTank(float fuelInput){
  if(fuelInput <= 0){
    cerr << "Error: Invalid fuel input. Permitted Range: > 0" << endl; 
    return;
  }
  else if((fuel + fuelInput) > maxFuel){
    cerr << "Error: fuel input exceeds tank capacity" << endl;
  }
  else{
    fuel += fuelInput; 
  }
}

/*
  Function takes a float parameter as indicator of # miles driven.
  The function then calculates various outputs. 
  Pre Condition:
    milesTrav > 0 
*/
void automobileType::drive(float milesTrav){
    float gallonsUsed;
    float possibleDist; 

      //first do a 0 miles check
    if(milesTrav <= 0){
      cerr << "Error: cannot drive negative miles." << endl;
       return; 
    }
       
    //if fuel <= 0 then just exit immeaditley 
    
     //do a formula to figure how many gallons we used 
     gallonsUsed = (1 / efficiency) * milesTrav; 

     //precalculate how many miles the car can drive 
     possibleDist = fuel * efficiency; 

      //if the fuel level goes below 0 then we're out of gas 
    if((fuel - gallonsUsed) <= 0){
      cerr << "Error: Out of gas. Refill tank" << endl;
      fuel = 0; 
    }
    else {
      fuel -= gallonsUsed; //subtract gallons used from our fuel
    }
    //cout << odemeter + milesTrav << endl;
    if((milesTrav) > possibleDist){ 
      odemeter += possibleDist; 
    }
    else{
      //add this vechile has traveled to the odemeter
       odemeter += milesTrav;
    }
    
}

//default constructor
automobileType::automobileType(){
  odemeter = DEFAULT_ODEMETER;
  fuel = DEFAULT_FUEL_LEVEL;
  efficiency = DEFAULT_EFFICIENY;
  maxFuel = DEFAULT_MAX_FUEL; 
}

/*
  Parameterized constructor that takes 3 float arguements to set the intial
  state of object. 
  Pre Condition:
    odmtrInput > 0 or odmtrInput > odemeter 
    fuelInput >= 0 or fuelInput < maxFuel
    effoInput > 1

*/
automobileType::automobileType(float odmtrInput, float fuelInput, float effoInput, float maxFuelInput){
  const int INVALID = -1;
 
  //first we want to set the maxFuel && do prelimary check
  if(maxFuelInput > 0){
    maxFuel = maxFuelInput;
  } else {
    cerr << "Error: Invalid max fuel value" << endl;
    maxFuel = DEFAULT_MAX_FUEL; 
    cerr << "Res: Max fuel set to 20 by default" << endl; 
  }

   //call setFuel. If invalid set it to default
  if(setFuelLevel(fuelInput) == INVALID){
    fuel = DEFAULT_FUEL_LEVEL; 
    cerr << "Res: Fuel level set to 15 by default. " << endl;
  }

  if(setOdemeter(odmtrInput) == INVALID){
    odemeter = DEFAULT_ODEMETER;
    cerr << "Res: Odemeter set to 0 by default."<< endl;
  }

  if(setEfficiency(effoInput) == INVALID){
    efficiency = DEFAULT_EFFICIENY; 
    cerr << "Res: Efficiency set to 30 by default."<< endl; 
  }

}