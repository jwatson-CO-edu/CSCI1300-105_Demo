#include <string>
#include <iostream>
#include <cmath> // min/max // NEW  // NEW  // NEW 
using namespace std;

class Animal{

// Access Specifier - `public`
public: // Public interface used by other code

// ~~~ 1. Method (Member Function) Prototypes / Signatures ~~~

    // ~ A. Constructors ~
    Animal(); // "Default" constructor
    Animal( string nam , string sound , double initHP , double initPower );
    // NOTE: If you define a constructor, then a default constructor is not created

    // ~ B. Methods ~
    string get_name(); // ------------ Return name  // NEW  // NEW
    void   make_sound(); // ---------- Print the default sound
    double eat( double nutrition ); // Consume nutrition and return HP
    
    double take_damage( double damage ); // Reduce, check, and return HP // NEW  // NEW  
    bool   is_alive(); // ------------ Return true if animal alive. otherwise false // NEW 

// Access Specifier - `private`
private: // Private data managed by this object only

    // ~ B.1. Private Methods ~
    double check_HP(); // Prevent nonsense values and set Alive/Dead // NEW  // NEW  // NEW 

// ~~~ 2. Member Variables (Properties) ~~~

    // ~ C. Intialize with default values ~
    string name  = "Animal"; // Identifies animal
    string call  = "werp!"; //- Default sound it makes
    double HP    = 10.0; // --- Health
    double mxHP  = 10.0; // --- Maximum HP // NEW  // NEW  // NEW  // NEW  // NEW  // NEW 
    double PW    = 10.0; // --- Power
    bool   alive = true; // --- true if HP>0, otherwise false
};
