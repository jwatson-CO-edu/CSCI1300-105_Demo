#include <iostream>
#include <math.h>
using namespace std;

// Function DECLARATION
double distance_2D( double , double , 
                    double , double );
/* * You cannot USE the function `distance_2D` before it is DECLARED.
   * You don't have to name the variables in the declaration, but you can. 
   * This function to be defined later ... */

int main(){

    double p1x =  2.5 , // p1 = (  2.5 ,  1.3 )
           p1y =  1.3 ,
           p2x = -4.5 , // p2 = ( -4.5 , -0.7 )
           p2y = -0.7 ;

    cout << "Distance between the two points: "
         << distance_2D( p1x , p1y , 
                         p2x , p2y ) << endl;

    return 0;
}

// Function DEFINITION
double distance_2D( double x1 , double y1 , 
                    double x2 , double y2 ){
    // Return the Euclidean distance between 2 two-dimensional points
    return sqrt(  pow( x1-x2 , 2.0 )  +  pow( y1-y2 , 2.0 )  );
}