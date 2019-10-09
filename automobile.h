/*
    Header file for the automobileType class
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
            Function takes 3 parameters to set the odemeter, fuel, and effiency.
            If any values are below 0 then they are automatically set to 0
            Post Condtion:
                odemeter = odmter
                fuel = fuelLevel
                efficieny = effo
        */
        std::string getInfoString() const;
        /*
            Function that returns a string with an update of all 3 properties.
            private members are not mutated, but have copies that are converted
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
        void setOdemeter(float);\
        /*
            Function takes a float arguement and uses it to set the odemeter
            Conditionals are in place to make sure the odemeter is neither negative
            nor lower than the current value.
            Post Condition:
                odemeter = odmtrInput

        */
        void setFuelLevel(float);
        /*
            Function takes a float arguement and uses it to set the fuel level.
            Conditionals are in place to make sure the fuel level doesn't exceed 
            the tank's max capacity and is not a negative input value. 
            Post Condition:
                fuel = fuelInput
        
        */
        void setEfficiency(float); 
        /*
            Function takes a float arguement and uses it to to set the efficiency. 
            Conditionals are in place to make sure the efficiency is never set 
            below 1.
            Post Condition:
                efficiency = effoInput
        
        */
        
        void drive(float);
        /*
            Function takes a parameter for amount of miles the car has driven.
            The function then calculates the new fuel level and updates the
            odemeter. 
            Post Condition:
                fuel -= gallonsUsed
                odemeter += milesTrav
        */
        automobileType();
        /*
            Default constructor for automobileType. 
            Calls the setProperties function to set all to 0
            Post Condition:
                setProperties(0,0,0)
        */
        automobileType(float, float, float, float);
        /*
            Constructor that takes parameters to initialize automobileType
            Post Concdtion:
                setProperties(float, float , float)
        */

    private:
        float odemeter;
        float fuel;
        float efficiency; 
        float maxFuel;
};