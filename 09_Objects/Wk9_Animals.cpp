#include "Wk9_Animals.h"

// CLASS::FUNCTION
Animal::Animal( string nam , string sound , double initHP , double initPower ){
/* These -------> */ name = nam; // _____ Identifies animal
/* member vars -> */ call = sound; // ___ Default sound it makes
/* exist in ----> */ HP   = initHP; // __ Health
/* animal ------> */ PW   = initPower; // Power
    cout << "`Animal` constructor created: " << name << endl;
}

// Constructors are special, their return type is implied: The Class
Animal::Animal(){
    cout << "The \"default\" `Animal` constructor was called" << endl;
}

// RETURN_TYPE CLASS::FUNCTION_NAME
void Animal::make_sound(){
    // Print the default sound
    cout << name << " said " << call << endl;
} 

double Animal::eat( double nutrition ){
    // Consume nutrition and return HP
    HP += nutrition;
    return HP;
}