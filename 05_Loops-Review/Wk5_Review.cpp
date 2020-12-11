#include <iostream>
#include <iomanip>
#include <string> // C++ strings are not primitive types, need to get lib
/* ~ Primitive/Basic Types ~ 
Covered: int , float , double , char , bool
Also:    unsigned int , unsigned long int , void , size_t 
*/
// #include <integer> // Primitive types don't require libraries!
using namespace std;

int main(){

    // ~~~ 1. Variables , Casting , Imlicit Casting ~~~

    double N_dbl = 14.5; // INITIALIZATION is almost always a good idea!
    
    // Casting: Explicitly or implicitly converting an expression of one type to another
    float N_flt = N_dbl; // Imlicit cast
    int   N_int = N_dbl; // Imlicit cast
    // string N_str  = N_dbl; // CANNOT cast
    // Converting: Changing type when a direct relationship isn't part of the language
    string N_str = to_string( N_dbl ); // Must use lib function to convert to string

    // What did we get?
    cout << "N_dbl: " << N_dbl << endl // There was a time when double math was slow, only use float
         << "N_flt: " << N_flt << endl // if resources are very limited or application vary fast
         << "N_int: " << N_int << endl
         << "N_str: " << N_str << endl << endl; // Conversion function chose precision
    // [Review output]

    // Implicit cast:
    double dbbl_implicit = 4 * 1.0 / 5; // Any expression that includes float returns float
    // Explicit cast:
    double dbbl_explicit = (double) 4 / 5; // Cast directly

    cout << "Are these expressions equal? " << ( dbbl_implicit == dbbl_explicit ) 
         << " , and they are equal to " << dbbl_implicit << endl;
    // [Review output]

    // ~~~ 2. char -vs- string ~~~
    char   a = 'a'; // Char   literals get SINGLE quotes
    string A = "A"; // String literals get DOUBLE quotes, There IS a DIFFERENCE
    cout << a << '\n'     << '\t' << A << endl << endl;
    /*            ^newline    ^tab    <-- Escaped characters allow us to print 
                                          non-alphanum characters to standard output */
    // [Review output]

    // ~~~ 3. Increment, Decrement, and Unary Math ~~~
    int n = 5;
    cout << "Begin with value: " << n   << endl;
    n++;
    cout << "After n++ : _____ " << n << endl;
    n--;
    cout << "After n-- : _____ " << n << endl;
    n+=5;
    cout << "After n+=5 : ____ " << n << endl;
    n-=2;
    cout << "After n-=2 : ____ " << n << endl;
    n/=4;
    cout << "After n/=4 : ____ " << n << endl;
    n*=100;
    cout << "After n*=100 : __ " << n << endl << endl;

    // ~~~ 4. Conditionals and Testing ~~~

    // To Do: Test whether a number lies in the rang [ 4,10] (inclusive)
    int lower   =  4 ,
        upper   = 10 ,

    // WHY is my code WRONG??!    Strive to test every state that your program can be in ...
    // State: The combination of location in program execution and values of all variables
        inside  =  5 , // Test when you think a condition is TRUE
        outside = 19 , // Test when you think a condition is FALSE
        edge    = 10 ; // Test the EDGES of your cases!
    // ^^^ Multiple declaration and initialization ^^^

    // We construct a range tests with compound logcial statements
    // Testing if in range
    cout << "Is `inside`  within  the range?: " << ( lower <= inside  && inside  <= upper ) << endl
         << "Is `outside` within  the range?: " << ( lower <= outside && outside <= upper ) << endl
         << "Is `edge`    within  the range?: " << ( lower <= edge    && edge    <= upper ) << endl
         // Now let's constuct the opposite case ... 
         << "Is `outside` outside the range?: " << ( lower > outside || outside > upper ) << endl << endl;
         // Note that conditions can't possibly ## (     below       OR       above     )    
         // be true simultaneously, need OR     ##
    // [Review output]
    

    // ~~ 5. Compound if and gotcha ~~

    string country = "USA" , 
           state   = "CO"  ;
    double charge  = 5.00; // Default to the continental rate

    if( country == "USA" )
        if( state == "HI" )
            charge = 10.00; // non-continental USA rate
    else
        charge = 20.00; // International rate
    // The indentaion is good for human readers but does not determine program flow!
    cout << "BAD: ___ The shipping charge for " << state << ", " << country << " is $" << charge << endl;
    // [Review output]

    charge  = 5.00; // Default to the continental rate
    if( country == "USA" ){
        if( state == "HI" ){
            charge = 10.00; // non-continental USA rate
        }
    }else{
        charge = 20.00; // International rate
    }
    cout << "CORRECT: The shipping charge for " << state << ", " << country << " is $" << charge << endl
         << endl;
    // [Review output]

    // Sneaky
    if( 5 < 4 );{
        cout << "5 is less than 4" << endl << endl;
    }
    // [Review output]
        

    // ~~ 6. Switch ~~
    // Pass any int or char expression to `switch`

    int menu = 2;

    cout << "Chose ";
    switch( menu ){

        case 1:
            cout << "Chicken";
            break;

        case 2:
            cout << "Salmon";
            // What happens when value is 2?

        case 3:
            cout << "Tofu";
            break;
            // What happens when value is 3?

        case 4:
            cout << "Mushroom";
            break;

        default:
            cout << "This option not available!";
    }
    cout << " from the menu." << endl << endl;
    // [Review output]

    // exit( 0 ); // Comment out to continue with review
    /* You can immediately exit the main program with `exit`.  Not recommended, 
       as you are essentially crashing your program on purpose, and makes program harder to debug.
       ( Consequences are low unless we are dealing with dynamic memory. ) */


    // ~~ 7. Loops ~~

    // while
    // PRO: Runs conditionally, adaptable
    // CON: You are responsible for UPDATING variables checked by condition, possibly infinite
    int i = 1; 
    while( i < 6 ){ // FIXME
        cout << i << ", ";
        i+=2; 
    }
    cout << endl;
    // [Review output]



    // spaaaaaace







    // do-while
    // PRO: Form of while that guarantees one run
    // CON: Same as above
    i = 0;
    do{
        cout << i << ", ";
        i++;
    }while( i < 3 ); // do-while ends in SEMICOLON!
    cout << endl << endl;

    // for loop and variable scope
    /* PRO: + Control exactly how many times loop will run
            + Compact, flexible syntax (Any expression, even EMPTY)
       CON: - Definition can be hard to understand
            - Not adaptable */
    
    cout << "Value of `i` before for-loop: " << i << endl;
    for( int i = 1 ; i < 7 ; i+=2 ){ 
        // This `i` is local to the loop body!
        cout << i << ", ";
    }
    /* When C++ substitutes a variable name for it's value, it begins with the innermost scope and
       searches outwards until it either finds a matching name or the search fails at the global
       (program-level) scope. */
    cout << endl << "Value of `i` after for-loop: " << i << endl << endl;
    // In fact, we did not have to use the local `i`, we could have used ANY variable
    // that has scope here as the counter

    // Likewise, variables declared within ANY code block are LOCAL
    int j = 1;
    cout << "Value of `j` before code block: " << j << endl;
    { // Any value other than 0 is considered "true"
        int j = 5;
        j += 5;
        cout << "Value of `j` within code block: " << j << endl;
    }
    cout << "Value of `j` after  code block: " << j << endl << endl;

    // exit( 0 ); // Comment out to continue with review


    // ~~ 7. Input/Output ~~

    int AA , BB , CC;
    cout << "Enter 'AA' value: ";
    cin  >> AA;
    cout << "Enter 'BB' and 'CC' values, in order, separated by a space: ";
    cin  >> BB >> CC;
    cout << "You entered A = " << AA << ", BB = " << BB << ", CC = " << CC << endl << endl;


    // ~~ 8. Strings ~~

    // This is kind of a densely-packed segment, sorry!

    /* To Do: - Find all the instances of `key` within `corvids`,
              - report where they are in the string, and
              - accumulate the substrings into another string */
    string corvids = "crow crow raven crow raven magpie crow";
    string key     = "crow";
    string hits; // This initializes to an empty string
    // `size_t` is a special unsigned integer whost max value is the maximum integer 
    //  that your system architecture can represent
    size_t last_i  = 0; // 1. Init counting var
    do{ // 2. Do the following at least once ....
        last_i = corvids.find( key , last_i ); // 3. Search larger string for `key`
        /* `string::npos` is a special value that signifies an invalid index within a string */
        if( last_i != string::npos ){ // 4. If a matchin substring is found , Then ....
            // 5. Report where the search term was found within `corvids`
            cout << "Found the search term " << key << " at index " << last_i << endl;
            // 6. Concatenate this particular substring to `hits`
            hits += corvids.substr( last_i , key.length() ); 
            // 7. Important! Update index where search begins! Why?
            last_i += key.length();
        }
    }while( last_i != string::npos ); // 7. If the last search succeeded, then loop again
    
    cout << hits << " is called a \"murder\"!" << endl;
    /* Escaped characters         ^^      ^^
       because double-quotes signify the beginning and end of string literals */

    return 0;
}
