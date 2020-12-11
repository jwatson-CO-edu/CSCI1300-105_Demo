
#include <iostream> // Input and output
#include <cmath> // -- pow
#include <stdlib.h> // srand, rand
#include <time.h> // - time

using std::cout;  using std::cin;  using std::endl;

int main(){ double    quotient;double    quotOfInts;int       important = 1;
const int NUMLOOPS  = 5;quotient   = 2.0 / 5;quotOfInts = 2   / 5; // int/int
    
cout << endl;
    cout << "quotient: ___ " << quotient   << endl;
cout << "quotOfInts: _ " << quotOfInts << endl;
    cout << "What is 5/2?: " << 5/2 << endl << endl;  // int/int


            /* 1 --> */            // Get input
            /* 2 --> */            cout << "What is the most important number?: "; 
            /* 3 --> */            cin >> important;
            /* 5 --> */            cout << endl; // Print an empty line
    
    
    if( important > NUMLOOPS ){ cout << "`important` is greater than `NUMLOOPS`" << endl;
    }else if( important < NUMLOOPS ){ cout << "`important` is lesser than `NUMLOOPS`" << endl;
    }else // else WHAT?
        





cout << "`important` is equal `NUMLOOPS`" << endl; cout << endl;
    for(int i=0;i<NUMLOOPS;i++){cout << "On loop " << i+1 << " of " << NUMLOOPS 
<< ", i= " <<  i << ", i^2= " << pow( i , 2 ) << endl; } cout << endl; srand( time(NULL) ); /* initialize random seed: */
    int dieRoll = rand() % 100 + 1; while( dieRoll >= important ){
        cout << "Rolled " << dieRoll << ", "; dieRoll 
        
        = 
        rand() 
        
        % 100 + 
        1
        
        
        ; // Roll again
    }
    cout 
        << 
            endl 
            // Print // Print // Print // Print // Print // Print 
                << 
                    "Rolled " 
                        << 
                            dieRoll 
                                << 
                                // Print 
                                    ", Lesser than " 
                                        << 
                                            important 
                                                << 
                                                    endl;
                                                        return 
                                                            0
                                                                ;
}