// INCLUDE GUARDS ALWAYS ALWAYS
#ifndef HELPERS1300_H
#define HELPERS1300_H

#include <string>
#include <sstream>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <chrono> // more different time
#include <iostream>
#include <vector>

using namespace std;

// Use `typedef` to create aliases for TYPES
typedef  std::chrono::steady_clock::time_point  StdTime;
typedef  std::chrono::steady_clock              StdClock;


// === 101 Helper Functions ===

double rand_01(); // Return a (mostly) uniformly distributed random number on the interval [0,1)

double time_elapsed( StdTime& clok ); // Return the time since the last function call

string TF( bool cond ); // Print conditional results in a readable way

// == Template Functions ==
// NOTE: Any templated function must be DEFINED in the HEADER
//       You cannot move the definition to the CPP.

template<typename T> // Advanced Topic: TEMPLATES
void print_vector( vector<T>& v , bool NL = true ){
    // Print a vector in a pretty way
    cout << "[ ";
    size_t len = v.size(); // Reduce number of function calls
    for( size_t i = 0 ; i < len ; i++ ){  
        cout << v[i] << ( i<len-1 ? "," : "" ) << " ";  
    }
    cout << "]";
    if( NL )  cout << endl;
};

template<typename T> // Advanced Topic: TEMPLATES
void print_array( T a[] , size_t len ,  bool NL = true ){
    // Print an array in a pretty way
    cout << "[ ";
    for( size_t i = 0 ; i < len ; i++ ){  
        cout << a[i] << ( i<len-1 ? "," : "" ) << " ";  
    }
    cout << "]";
    if( NL )  cout << endl;
};

template<typename T> 
void print_hex_data( T a , bool nwln = true ){
	// Print the hexadecimal representation of a uint
    int sz = sizeof( a );
    // cout << "Got size: " << sz << endl;
	unsigned char byte;
	printf( "0x " );
	for( int i = sz-1 ; i > -1 ; i-- ){ 
		byte = ( a >> ( i*8 ) ) & 0xFF;
        // cout << to_string<T>( byte , hex ) << " ";
        printf( "%02hhX " , byte );
	}  
    if( nwln )  cout << endl;
};

template<typename T> 
void print_hex_address( T a , bool nwln = true ){
    // Print the pointer address
    void* p = (void*)a;
    stringstream strs;
    // strs << hex << static_cast<void*>( a ) << ( nwln ? "\n" : "" );
    strs << p;
    string hexStr = strs.str();
    string prntStr;
    int len = hexStr.length();
    for( int i = 0 ; i < len ; i++ ){
        prntStr += ( i>1 ? toupper( hexStr[i] ) : hexStr[i]);
        prntStr += ( i%2 ? " " : "" );
    }
    cout << prntStr << ( nwln ? "\n" : "" );
};


// __ End Templates __

// ___ End Helpers ___


#endif