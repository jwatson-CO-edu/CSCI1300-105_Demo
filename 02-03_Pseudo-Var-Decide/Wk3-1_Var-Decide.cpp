// Include libraries with useful functions
#include <iostream> // Input and output
#include <cmath> // -- pow
#include <stdlib.h> // srand, rand
#include <time.h> // - time

/* You don't have to use an entire namespace, 
   you can use specific variables and functions within the namespace.
   This will make compilation times *shorter*. */
using std::cout;
using std::cin;
using std::endl;

/* block comments
   can span
   multiple lines */

// Main program function
int main(){ 

    // 1. Create/declare/initialize variables
    // a. Declare variables without initializing
    double    quotient; 
    double    quotOfInts;
    // b. Declare and initialize in a single statement
    int       important = 1;
    const int NUMLOOPS  = 5;
    
    // Modify variables
    quotient   = 2.0 / 5; // double/int
    quotOfInts = 2   / 5; // int/int
    
    // Produce output
    cout << endl;
    cout << "quotient: ___ " << quotient   << endl;
    cout << "quotOfInts: _ " << quotOfInts << endl;
    cout << "What is 5/2?: " << 5/2 << endl << endl;  // int/int

    // Get input
    cout << "What is the most important number?: "; // Do not HAVE to end with `endl`
    cin >> important;
    cout << endl; // Print an empty line
    
    // cout << "How many loops to run?: ";
    // cin >> NUMLOOPS; // Why does this result in an error?
    
    // Check for true/false and make decisions
    if( important > NUMLOOPS ){
        cout << "`important` is greater than `NUMLOOPS`" << endl;
    }else if( important < NUMLOOPS ){
        cout << "`important` is lesser than `NUMLOOPS`" << endl;
    }else // We don't have to put a single statement in { curly braces }
        cout << "`important` is equal `NUMLOOPS`" << endl;
    
    cout << endl;
    
    // Repeat a block of instructions (if needed)
    for( int i = 0 ; i < NUMLOOPS ; i++ ){ // `i++` same as `i=i+1`
        cout << "On loop " << i+1 << " of " << NUMLOOPS 
             << ", i= " <<  i << ", i^2= " << pow( i , 2 ) << endl;
    } 
    cout << endl;

    // http://www.cplusplus.com/reference/cstdlib/rand/
    srand( time(NULL) ); /* initialize random seed: */
    int dieRoll = rand() % 100 + 1; // Obtain int in [1,100]
    
    // While the random die roll is >= our `important` number, keep rolling
    while( dieRoll >= important ){
        cout << "Rolled " << dieRoll << ", ";
        dieRoll = rand() % 100 + 1; // Roll again
    }
    cout << endl << "Rolled " << dieRoll << ", Lesser than " << important << endl;

    return 0; // Common to return 0 from `main` if nothing has gone wrong
}