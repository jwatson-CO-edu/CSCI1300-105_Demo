// g++ -std=c++11 Wk12_Recursion.cpp  1300_101_helpers.cpp

#include <iostream>
#include <vector>

#include "1300_101_helpers.h" // Our own library!

using namespace std;

// ~~~ TOPIC 1 : RECURSION ~~~

unsigned long int fibonacci_R( unsigned long int n ){
    // Compute the n^th Fibonacci, Recursively
    
    // Base Cases: The smallest possible sub-problems
    // Typically these require little or no calculation
    if( n <= 1 )  return 0; 
    if( n == 2 )  return 1;
    
    // Recursive Case: Defined using at least one sub-problem
    // Else: Number is greater than 2
    return fibonacci_R( n-2 ) + fibonacci_R( n-1 );
}


// ~~~ TOPIC 2 : MEMOIZATION ~~~

unsigned long int fibonacci_RM( unsigned long int n , vector<unsigned long int>& mz ){
    // Compute the n^th Fibonacci, Recursively.  Now with memoization
    
    if( n == 0 ){ // Now we need an error check to prevent bad vector access
        return 0;
    }else if( n <= mz.size() ){ // Check if we have done this work before
        return mz[ n-1 ];
    }else{ // Else have not done this work before: calc, store, and return
        unsigned long int rtnVal = 0; // Create a var to store and return
        
        // Base Cases: The smallest possible sub-problems
        // Typically these require little or no calculation
        if( n == 1 ){
            rtnVal = 0; 
        }else if( n == 2 ){
            rtnVal = 1;

        // Recursive Case: Defined using at least one sub-problem
        // Else: Number is greater than 2
        }else{
            rtnVal = fibonacci_RM( n-2 , mz ) + fibonacci_RM( n-1 , mz );
        }

        // Save our work:
        mz.push_back( rtnVal );

        // Return the work
        return rtnVal;
    }
}

int main(){

    vector<unsigned long int> mem;
    StdTime clk;

    // These should have the same result
    cout << fibonacci_R( 13 ) << endl;
    cout << fibonacci_RM( 13 , mem ) << endl;
    // What should the final size of `mem` be?
    cout << mem.size() << endl;

    mem.clear(); // Clear old work for a fair comparison

    double run1 = 0.0 ,
           run2 = 0.0 ;

    time_elapsed( clk ); // Start timer
    cout << fibonacci_R( 45 ) << endl;
    run1 = time_elapsed( clk );
    cout << "Recursive running time: " << run1 << " [s]" << endl;
    
    time_elapsed( clk ); // Start timer
    cout << fibonacci_RM( 45 , mem ) << endl;
    run2 = time_elapsed( clk );
    cout << "Memoized running time: " << run2 << " [s]" << endl;
    cout << run1 / run2 << "x speedup with memoization!" << endl;
    return 0;
}

// g++ -std=c++11 Wk12_Recursion.cpp  1300_101_helpers.cpp