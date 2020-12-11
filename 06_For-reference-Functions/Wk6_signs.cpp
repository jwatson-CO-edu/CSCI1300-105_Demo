#include <iostream> /* cout, etc */
#include <math.h> /* pow */
using namespace std;

int sign1( int x ){
    if( x > 0 )  return  1;
    if( x < 0 )  return -1;
}

int sign( int x ){ // Multiple return
    if( x > 0 )  return  1;
    if( x < 0 )  return -1;
    return 0;
}

int sign2( int x ){ // single return
    int rtnSgn = 0;
    if( x > 0 ){ 
        rtnSgn = 1;
    }else if( x < 0 ){
        rtnSgn = -1;
    }
    return rtnSgn;
}

// This function is overloaded, meaning more than one function of the same name
// has a different signature
int sign( double x ){
    if( x > 0 )  return  1;
    if( x < 0 )  return -1;
    return 0.0;
}

int main(){
    cout << "Compare `signX` functions: " << endl
         << "sign1( 0 ) = " << sign1( 0 ) << endl
         << "sign( 0 )  = " << sign( 0 )  << endl
         << "sign2( 0 ) = " << sign2( 0 ) << endl 

         << "What about decimal numbers?" << endl
         << "sign( -0.99 )  = " << sign( -0.99 )  << endl;
}