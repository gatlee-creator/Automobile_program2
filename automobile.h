/*
    Name: Graham Atlee
    Course: csc1720
    Date: 10/10/2019
    Location of Program: ~/csc1720/Programs/program2

    Header file for the automobileType class. The code below 
    contains function prototypes and variables relevant to 
    the automobileType. Under each function contains further 
    documentation. 
*/


#include <string>

class automobileType{
    public:

        const float DEFAULT_FUEL_LEVEL =  15; 
        const float DEFAULT_MAX_FUEL = 20; 
        const float DEFAULT_ODEMETER = 0;
        const float DEFAULT_EFFICIENY = 30; 


        void setProperties(float, float, float);
        /*
            Function takes 3 float parameters to set the odemeter, fuel, and effiency.
            Post Condtion:
                odemeter = odmter
                fuel = fuelLevel
                efficieny = effo
            Conditionals are in place to check if the input values are within the 
            permitted range. If any input values are invalid then none of 
            the values are set.
        */
        std::string getInfoString() const;
        /*
            Function that returns a string with a current update of all 3 properties.
            Private members are not mutated, but have copies that are converted
            to strings. 
            Post Condition:
                "Miles = odemeter, Fuel = fuelLevel, efficieny = effo"
        */
        float getOdemeter();
        /*
            Function that returns the current odemeter value 
            Post Condition:
                return odemeter
        */
        float getFuelLevel();
        /*
            Function that returns the current fuel level
            Post Condition:
                return fuel
        */
        float getEfficiency(); 
        /*
            Function that returns the current efficiency 
            Post Condition:
                return efficiency 
        */
        int setOdemeter(float);
        /*
            Function takes a float arguement and uses it to set the odemeter
            Conditionals are in place to make sure the odemeter is neither negative
            nor lower than the current value.
            Post Condition:
                odemeter = odmtrInput
            If the arguement passed violates any of the conditions then -1 is returned.å
            Post Condition:
                return -1 

        */
        int setFuelLevel(float);
        /*
            Function takes a float arguement and uses it to set the fuel level.
            Conditionals are in place to make sure the fuel level doesn't exceed 
            the tank's max capacity and is not a negative input value. 
            Post Condition:
                fuel = fuelInput
            If the arguement passed in violates any of the conditions then -1 is returned.
            Post Condition:å
                return -1 
        
        */
        int setEfficiency(float); 
        /*
            Function takes a float arguement and uses it to to set the efficiency. 
            Conditionals are in place to make sure the efficiency is never set 
            below 1.
            Post Condition:
                efficiency = effoInput
            If the arguement passed in violates any of the conditions then -1 is returned.
            Post Condition:å
                return -1 
        */
        void refillTank(float);
        /*
            This function takes a float parameter and adds to the current fuel.
            In turn this refills the fuel tank. 
            Post Condition:
                fuel += fuelInput
            Conditionals check if the input value exceeds the tank capacity or
            if it is below 1. 
        */
        void drive(float);
        /*
            Function takes a parameter for amount of miles the car is to drive.
            The function then calculates the new fuel level and updates the
            odemeter. 
            Post Condition:
                fuel -= gallonsUsed
                odemeter += milesTrav
            Function also calculates the possible driving range of the car. If
            the input value exceeds this then the car will run out of fuel. In 
            like manner,the odemeter only increases by the actual number 
            of miles driven.   
        */
        automobileType();
        /*
            Default constructor for automobileType. 
            DEFAULTS_VALUES are assigned to each of the private variables.
            Post Condition:
                  odemeter = DEFAULT_ODEMETER
                  fuel = DEFAULT_FUEL_LEVEL
                  efficiency = DEFAULT_EFFICIENY
                  maxFuel = DEFAULT_MAX_FUEL
        */
        automobileType(float, float, float, float);
        /*
            Constructor that takes 3 parameters to initialize automobileType. 
            The setFunctions are called to set the properties odemeter, fuel, efficiency.
            Post Condtion:
                if(setFuelLevel(fuelInput) == INVALID)
                if(setOdemeter(odmtrInput) == INVALID)
                if(setEfficiency(effoInput) == INVALID)
            The conditional wrapped around the setFunctions are used so that any/all 
            invalid parameters are set to DEFAULT_VALUES to ensure the constructed 
            object is immediately usable.
        */

    private:
        float odemeter;
        float fuel;
        float efficiency; 
        float maxFuel;
};