#include <iostream> // cout
#include <vector> // Easy mode arrays
#include <string>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <chrono> // more different time

// ~~ Namespace Manip ~~
using namespace std;
// Use `typedef` to create aliases for TYPES
//       Complete type name                     Alias (Easier to remember)
typedef  std::chrono::steady_clock::time_point  StdTime;
typedef  std::chrono::steady_clock              StdClock;


double rand_01(){ // NOTE: Not the best way for uniform rand, but is EASIEST
    // Return a random number on [0,1)
    // NOTE: This function assumes that an appropriate random seed was set in `main`
    return rand() / ( RAND_MAX + 1.0 );
}

double time_elapsed( StdTime& clok ){
    StdTime t = StdClock::now();  // 1. Get the time now
    // 2. Compute span and convert microseconds to seconds
    double elapsed = 
        chrono::duration_cast<chrono::microseconds>(t - clok).count()
        / (double) 1e6;
    // 3. Reset the time marker var        
    clok = t;
}

void fill_array_rand( double arr[] , size_t len ){
    // Populate an array with random doubles on [0,1)
    for( size_t i = 0 ; i < len ; i++ ){
        arr[i] = rand_01();
    }
}

void fill_vector_rand_BAD( vector<double> vctr , size_t len ){
    // What happens to `vctr` ?
    for( size_t i = 0 ; i < len ; i++ ){
        vctr.push_back( rand_01() );
    }
    cout << "There are " << vctr.size() << " elements in the vector" << endl;
}

void fill_vector_rand_GOOD( vector<double>& vctr , size_t len ){
    // THIS MAKES ALL THE DIFFERENCE -----^
    // What happens to `vctr` ?
    for( size_t i = 0 ; i < len ; i++ ){
        vctr.push_back( rand_01() );
    }
    cout << "There are " << vctr.size() << " elements in the vector" << endl;
}

template<typename T> // Advanced Topic: TEMPLATES
void print_vector( vector<T>& v , bool NL = true ){
    //                    Advanced Topic: ^^^^^^ DEFAULT ARGUMENT
    // Print elements of vector in between [ ... ]
    cout << "[ ";
    size_t len = v.size(); // Reduce number of function calls
    for( size_t i = 0 ; i < len ; i++ ){  
        cout << v[i] << ( i<len-1 ? "," : "" ) << " ";  
    }
    cout << "]";
    if( NL )  cout << endl;
}

template<typename T> // Advanced Topic: TEMPLATES
void print_array( T a[] , size_t len ,  bool NL = true ){
    //                          Advanced Topic: ^^^^^^ DEFAULT ARGUMENT
    // Print elements of vector in between [ ... ]
    cout << "[ ";
    for( size_t i = 0 ; i < len ; i++ ){  
        cout << a[i] << ( i<len-1 ? "," : "" ) << " ";  
    }
    cout << "]";
    if( NL )  cout << endl;
}

// Print conditional results in a readable way
string TF( bool cond ){  return cond ? "TRUE" : "FALSE";  }

// Array/vector manip
const size_t N = 5e6; // Scientific notation evals to double, implicit cast
double lrgArry[N];
double cpyArry[N];
vector<double> cpyVctr;
// Timekeeping
StdTime clk;
double  elapsed , elapsed1 , elapsed2;

int main(){

    // ~~~ 1. Array and Vector Benchmarking ~~~

    srand( time(NULL) ); // init random 

    // 1. Populate the array to be copied
    time_elapsed( clk ); // Init clock
    fill_array_rand( lrgArry , N );
    elapsed = time_elapsed( clk );
    cout << "Took " << elapsed << " seconds to fill array of " 
         << N << " elements" << endl;

    // 2. Copy array to array
    time_elapsed( clk ); // Init clock
    for( size_t i = 0 ; i < N ; i++ ){
        cpyArry[i] = lrgArry[i];
    }
    elapsed1 = time_elapsed( clk );
    cout << "Took " << elapsed1 << " seconds to populate array of " 
         << N << " elements" << endl;

    // 3. Copy array to vector
    time_elapsed( clk ); // Init clock
    for( size_t i = 0 ; i < N ; i++ ){
        cpyVctr.push_back( lrgArry[i] );
    }
    elapsed2 = time_elapsed( clk );
    cout << "Took " << elapsed2 << " seconds to populate vector of " 
         << N << " elements" << endl;

    cout << "Vector took " << elapsed2/elapsed1 << " times longer to copy" << endl;
    cout << "Sanity check: " 
         << TF( cpyArry[12345] == cpyVctr[12345] ) << endl << endl;


    // vvvv---- NOT USED THIS CLASS ----vvvv
    if( 0 ){
        // ~~~ 2. Vector and Array Copies and References ~~~
        vector<double> ex;
        // A. How does the vector start?
        print_vector( ex );
        cout << endl;
        
        // B. Attempt to populate with function
        fill_vector_rand_BAD( ex , 4 );
        cout << "Bad fill function:  ";
        print_vector( ex );
        cout << endl;

        fill_vector_rand_GOOD( ex , 4 );
        cout << "Good fill function: ";
        print_vector( ex );
        cout << endl;

        // C. What does it mean to assign a vector?
        vector<double> vA;
        vector<double> vB;

        fill_vector_rand_GOOD( vA , 4 );

        vB = vA; // EASY COPY
        cout << "vA: ";   print_vector( vA );
        cout << "vB: ";   print_vector( vB );

        vA[2] = 4;   cout << "Assign to `vA` ..." << endl;
        cout << "vA: ";   print_vector( vA );
        cout << "vB: ";   print_vector( vB );
        cout << endl;

        // D. What does it mean to assign an array
        double arA[4];
        double arB[4];

        cout << "`arA` wihtout init: ";   print_array( arA , 4 );   cout << endl;

        fill_array_rand( arA , 4 );
        // arB = arA; // ERROR
        // Must copy with code
        for( int i = 0 ; i < 4 ; i++ ){  arB[i] = arA[i];  }
        cout << "arA: ";   print_array( arA , 4 );
        cout << "arB: ";   print_array( arB ,4 );
    }
    return 0;
}