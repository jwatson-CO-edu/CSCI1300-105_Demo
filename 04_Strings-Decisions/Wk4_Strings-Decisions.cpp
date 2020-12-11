// ~~ Includes ~~
#include <iostream>
#include <iomanip>
#include <string>
// ~~ Shortcuts ~~
using namespace std;

int main(){

    int    iVar = 0 , // Can declare + initialize multiple vars of the 
           one  = 1 , // same type by separating `var = value` with commas,
           two  = 2 ; // and the last one must end in `;`, ALWAYS
    double dVar = 0.0;

    // ~~~~~ 1. Implicit Casting ~~~~~

    cout << "Enter a float value for `iVar`: "; // Try 1.999999999
    cin >> iVar;
    cout << "The value of `iVar` is: _______ " << iVar << endl;
    // Note that the fractional part is DROPPED no matter how close to 
    // the next whole number when (implicitly) casting to int

    dVar = one / two;
    cout << "What is `one / two`?: _____ " << dVar << endl;
    dVar = one * 1.0 / two;
    cout << "What is `one * 1.0 / two`?: " << dVar << endl << endl;
    /* Every expression that involves two types of precision will be implicitly cast
       to the highest precision
            int   * float  --> float
            float * double --> double */

    // ~~~~~ 2. Output Formatting ~~~~~
    int col1 = 6;
    int col2 = 9;

    string tea = "Tea"    , tPr = "$2.00" ,
           cof = "Coffee" , cPr = "$1.50" ,
           mlk = "Milk"   , mPr = ".50" ;

    // Fancy print formatting
    cout << std::left << std::setw(col1) << tea << std::right << std::setw(col2) << tPr << endl;
    // using namespace std; ......
    cout <<      left <<      setw(col1) << cof <<      right <<      setw(col2) << cPr << endl;
    cout <<      left <<      setw(col1) << mlk <<      right <<      setw(col2) << mPr << endl;

    // String concatenation
    // Declare string and initialize it as the concatenation of 2 string variables
    string teaPrice = tea + tPr; // String variables can be concatenated
    cout << teaPrice << endl << endl;
    // string cofPrice = "Coffee" + "$1.50"; // String literals can NOT be concatenated

    // ~~~~~ 3. String Operations ~~~~~
    string animals = "parrot frog wolf";
    string bird    = animals.substr(  0 , 6 );
    string mammal  = animals.substr( 12 );

    cout << "bird: _ " << bird << ", " << bird.length() 
         << " characters" << endl;

    cout << "mammal: " << mammal << ", " << mammal.length() 
         << " characters"  << endl << endl;

    // ~~~~~ 4. Ternary Operator ~~~~~
    string str1 , str2;
    // Conditionally run code with `if`
    if( 4 > 3 )
        str1 = "greater";
    else
        str1 = "lesser";
    // Ternary expression takes on the first value if condition is true, 
    // second value if condition is false
    str2 =  4>3  ?  "greater"  :  "lesser";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl << endl;

    // ~~~~~ 5. String Conversion ~~~~~
    // Assign strings
    string three  =  "3";
    string twelve = "12";
    // Convert to int with the `stoi` function, and assign to int
    int    i3     = std::stoi( three  );
    int    i12    =      stoi( twelve );
    /* Note how the `+` operator used with two types of operands (string+string, int+int).
       It does something different in each context, this is OPERATOR OVERLOADING */ 
    cout << "three + twelve = " << three + twelve << endl; // ------- String concatenation
    cout << "i3    + i12    = " << i3    + i12    << endl << endl; // Integer addition

    return 0;
}