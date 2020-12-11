// g++ -std=c++11 Wk13_Pointers.cpp 1300_101_helpers.cpp

#include <iostream>
#include <string>
#include "1300_101_helpers.h"
using namespace std;

int main(){ cout << endl;

    int* ptrInt; // !! NEVER DO THIS, EVERYTHING WILL BE DESTROYED !!


    // ~~~ Topic 1: A pointer holds an address in RAM ~~~

    // 1. Print the binary data that represents 1
    int a = 1;
    cout << "`a` in hex: "; 
    print_hex_data( a );
    cout << endl;

    // 2. What data is in an uninitialized pointer?
    cout << "Init address in `ptrInt`: "; 
    print_hex_address( ptrInt );
    cout << endl;

    // 2. What is the address of the null pointer?
    ptrInt = nullptr;
    cout << "Address of the null pointer: "; 
    print_hex_address( ptrInt , false );
    cout << ", Does the pointer have a valid address?: " + TF( ptrInt ) << endl;
    cout << endl;

    // 3. What data is in an uninitialized pointer?
    ptrInt = &a;
    cout << "Address of `a`: "; 
    print_hex_address( ptrInt , false );
    cout << ", Does the pointer have a valid address?: " + TF( ptrInt ) << endl;
    cout << endl;

    // exit(0); // FIXME: Remove for next section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // g++ -std=c++11 Wk13_Pointers.cpp 1300_101_helpers.cpp


    // ~~~ Topic 2: Manipulating addresses and the data you find there ~~~
    
    // 1. Storing an ADDRESS: Get an address with &<varName>
    int  i    = 4;  // Initialize an `int` as usual
    int* iPtr = &i; // Here `&` is the "address of" operator
    cout << "`i` has value " << i << " and can be found at "; print_hex_address( iPtr );
    cout << endl;

    // 2. Getting value AT an address: Get the value at the pointer address with *<ptrName>
    int  j    = *iPtr; // Initialize `j` with value at `iPtr` (`i`)
    				   // Here `*` is the "value at" operator
    cout << "Values: i = " << i << ", j = " << j << endl;
    j = 7;
    cout << "Assigning a new value, j = " << j << endl;
    cout << "Values: i = " << i << ", j = " << j << endl;
    cout << endl;

    // 3. Setting value AT an address: Assign value at the pointer address with *<ptrName>
    cout << "Assigning a new value at address ";   print_hex_address( iPtr, false );
    *iPtr  = 5;  // Here `*` is the "value at" operator
    cout << ", i = " << i << endl;
    cout << "Values: i = " << i << ", j = " << j << endl;
    cout << endl;

    // exit(0); // FIXME: Remove for next section ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // g++ -std=c++11 Wk13_Pointers.cpp 1300_101_helpers.cpp


    // ~~~ Topic 3: Treat pointers as `bool` to catch problems ~~~

    double* dPtr = nullptr; // Do you remember what the value of `nullptr` is?

    // 1. Test for a `nullptr`
    if( dPtr )
        cout << "`dPtr` POSSIBLY has an address ..." << endl;
    else
        cout << "`dPtr` has NOT been assigned an address!" << endl;

    // The following 2 statements compile, but crash the program when run.

    // 2. Attempt to get value stored at `nullptr`
    // double test = *dPtr; // Crash!

    // 3. Attempt to set value stored at `nullptr`
    // *dPtr = 3.1416; // This is a GOOD crash,
    //                 because we did not assign a value at a RANDOM address!

    return 0;
}

// // g++ -std=c++11 Wk13_Pointers.cpp 1300_101_helpers.cpp