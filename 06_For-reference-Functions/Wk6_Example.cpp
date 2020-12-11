#include <iostream> /* cout, etc */
#include <math.h> /* pow */
using namespace std;

const int CHARS_IGNORE = 10000;

double volume = 0.00 ,
       lrg    = 0.00 ;  // Cannot do assignment out of `main`, Only initialization

double cube_volume( double sideLen , double& largest ){
    /* Return the volume of cube with side length `sideLen`,
    Also, keep track of the largest cube stored in. 
    `sideLen` MUST be greater than 0, if not, then return NaN */
    if( sideLen <= 0.0 ) return nan(""); // Return Not-A-Number, float "error code"
    double volume = pow( sideLen , 3.0 ); // Will this modify the global `volume`?
    if( volume > largest ){  largest = volume;  } // Modify by reference
    return volume;
}
// Now try defining it within `main`

int main(){

    int input = -1;

    // ~~~ 0. Variable Scope in Nested Loops ~~~
    for( int i = -3 ; i < 0 ; i++ ){
        for( int j = -3 ; j < 0 ; j++ ){
            cout << i << " + " << j << " = " << i+j << ",   ";
        }    
        cout << endl;
        // cout << j << endl; // FIXME
    }
    // [Examine Output]

    // ~~~ 1. Handling bad input without crashing ~~~
    do{
        cout << "Enter a number >= 0: ";
        cin  >> input;
        if( cin.fail() ){ // Check if the failure bit has been set
            cin.clear(); // Set the failure bit to zero
            // Ignore 10000 chars or up to and including the first newline,
            // whichever comes first
            cin.ignore( CHARS_IGNORE , '\n' ); 
            // What's going on?
            input = -1; // https://stackoverflow.com/a/32378969
        }else{
            cout << "Got: " << input << endl;
        }
    }while(  input < 0  );
    cout << "The final value of `input` is: " << input << endl;

    // ~~~ 2. Functions and Variable References ~~~
    double vol2 = 0.00;

    volume = cube_volume( 2.0 , lrg );
    vol2   = cube_volume( 3.0 , lrg );
    
    cout << "volume: " << volume << endl 
         << "vol2: _ " << vol2   << endl
         << "lrg: __ " << lrg    << endl;
    // [Check output]
    
    double side  = 1.35;
    int    lrg_i = 0;
    cout << "Vol. with side " << side << ": "  
                                            << cube_volume( side  , lrg ) 
                                            << ",   lrg: " << lrg << endl;

    cout << "Vol. with side " << (4+5) << ": " 
                                            << cube_volume( 4+5   , lrg ) // FIXME
                                            << ",   lrg: " << lrg << endl;

    cout << "Vol. with side " << (4.5+5) << ": " 
                                            << cube_volume( 4.5+5 , lrg ) 
                                            << ",   lrg: " << lrg << endl;
    cout << "Sum of 3 cubes: " 
         << cube_volume(4.0,lrg) + cube_volume(5.0,lrg) + cube_volume(6.0,lrg)
         << ",   lrg: " << lrg << endl;
}

