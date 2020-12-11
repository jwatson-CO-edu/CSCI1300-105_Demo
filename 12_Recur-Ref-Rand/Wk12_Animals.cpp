#include "Wk12_Animals.h"

// CLASS::CLASS( <CONSTRUCTOR ARGS> )
Animal::Animal( string nam , string sound , double initHP , double initPower ){
    name = nam; // _____ Identifies animal
    call = sound; // ___ Default sound it makes
    HP   = initHP; // __ Health
    PW   = initPower; // Power
    mxHP = initHP; // __ Animals begin at max HP // NEW // NEW // NEW // NEW // NEW
    cout << "`Animal` constructor created: " << name << endl;
}

// Constructors are special, their return type is implied: The Class
Animal::Animal(){
    cout << "The \"default\" `Animal` constructor was called" << endl;
}

string Animal::get_name(){  return name;  }

// RETURN_TYPE CLASS::FUNCTION_NAME
void Animal::make_sound(){
    // Print the default sound
    if( alive )
        cout << name << " said " << call << endl;
    else
        cout << "There was no response from " << name << endl;
} 

double Animal::check_HP(){
    // Prevent nonsense values and set Alive/Dead
    
    /* ~ Data Model Rules ~ 
       1. HP cannot exceed the maximum value set at instantiation time
       2. HP cannot be less than zero
       3. 0.0 HP represents a dead animal 
       4. Dead animals do not make sounds 
       5. Dead animals do not eat */

    if( HP <= 0.0 ){ // If the HP has fallen to or below 0.0, then
        HP    = 0.0; // Set to zero
        alive = false;
    }else{ // else animal is alive, check that upper limit is not exceeded
        HP = min( mxHP , HP );
    }
}

double Animal::eat( double nutrition ){
    // Consume nutrition and return HP
    if( is_alive() ){ // Only living animals eat
        HP += nutrition;
        check_HP(); // Prevent immortal animals
    }
    return HP;
}

 double Animal::take_damage( double damage ){
    // Reduce, check, and return HP 
    HP -= damage;
    check_HP(); // Prevent immortal animals
    return HP;
 } 

bool Animal::is_alive(){
    // Return true if animal alive. otherwise false 
    return alive;
}

// NEW  // NEW  // NEW  // NEW  // NEW  // NEW  // NEW  // NEW  // NEW  // NEW  // NEW 

double Animal::get_max_HP(){
    // Return the max HP value
    return mxHP;
}

double Animal::get_HP(){
    // Return the current HP value
    return HP;
}