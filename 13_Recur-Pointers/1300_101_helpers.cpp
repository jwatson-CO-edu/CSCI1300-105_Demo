#include "1300_101_helpers.h"

double rand_01(){ // NOTE: Not the best way for uniform rand, but is EASIEST
    // Return a (mostly) uniformly distributed random number on the interval [0,1)
    // NOTE: This function assumes that an appropriate random seed was set in `main`
    //       srand( time(NULL) ); // init random <-- Paste in `main`
    return rand() / ( RAND_MAX + 1.0 );
}

double time_elapsed( StdTime& clok ){
    /* Return the time since the last function call
       NOTE: When a `StdTime` is instantiated, it will not have a meaningful value,
             therefore this function must be called once BEFORE the first timed interval */
    StdTime t = StdClock::now();  // 1. Get the time now
    // 2. Compute span and convert microseconds to seconds
    double elapsed = 
        chrono::duration_cast<chrono::microseconds>(t - clok).count()
        / (double) 1e6;
    // 3. Reset the time marker var        
    clok = t;
}

// Print conditional results in a readable way
string TF( bool cond ){  return cond ? "TRUE" : "FALSE";  }
