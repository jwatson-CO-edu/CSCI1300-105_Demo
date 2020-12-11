#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool str_has_newline( string str ){
    // Return `true` if `str` contains a newline, otherwise return `false`
    for( int i = 0 ; i < str.length() ; i++ )
        if( str[i] == '\n' )
            return true;
    return false; 
}

bool str_has_carriage_return( string str ){
    // Return `true` if `str` contains a carriage return, otherwise return `false`
    for( int i = 0 ; i < str.length() ; i++ )
        if( str[i] == '\r' )
            return true;
    return false; 
}

int main(){
    ifstream txtFile; // File handle
    string   line  , //- Most recent line of text read
             input ; 
    int      i = 0; // - Number of lines read

    cout << "Enter a filename: ";
    cin  >> input;

    // Open the file
    txtFile.open( input );

    if( txtFile.fail() ){
        cout << "Bad filename, revert to example ..." << endl;
        txtFile.open( "example.txt" );
        if( txtFile.fail() ){
            cout << "Could not open either, goodbye" << endl;
            return 1;
        }
    }
    
    while( getline( txtFile , line ) ){ // While there is a line to read
        i++;
        cout << "Line " << i << ":" << endl
             << '\t' << "Line has " << line.length() << " characters" << endl
             << '\t' << "Line has newline (\\n)?: " << str_has_newline( line ) << endl
             << '\t' << "Line has return (\\r)?: " << str_has_carriage_return( line ) << endl
             << '\t' << "Is an empty string?: " << ( line == "" ) << endl;
    }

}