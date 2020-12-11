#include <string>
#include <iostream>
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
    void   make_sound(); // ---------- Print the default sound
    double eat( double nutrition ); // Consume nutrition and return HP

// Access Specifier - `private`
private: // Private data managed by this object only

// ~~~ 2. Member Variables (Properties) ~~~

    /* We don't have to initialize properties, If we don't properties will begin 
       with garbage values (as expected), but if we initialize them here, 
       then the member vars take on these values unless the constructor assigns 
       otherwise. */
    // ~ C. Intialize with default values ~
    string name = "Animal"; // Identifies animal
    string call = "werp!"; //- Default sound it makes
    double HP   = 10.0; // --- Health
    double PW   = 10.0; // --- Power

};