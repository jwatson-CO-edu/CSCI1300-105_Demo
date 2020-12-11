#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> split_string( string input , char sep ){
    // Return a vector of strings found in `input` separated by `sep`
    vector<string> rtnWords;
    string /* - */ currWord;
    size_t /* - */ strLen = input.size();
    char /* --- */ currChar;
    
    for( size_t i = 0 ; i < strLen ; i++ ){
        // Your split here
    }
    return rtnWords; // This returns a COPY of `rtnWords`
}

// Same as other file, will cover user-defined libs later ...
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

int main(){

    // ~~~ 1. Open a file stream ~~~
    string   fName = "example.txt";
    ifstream fStrm;
    string   lineStr;
    char     sep = ',';

    // Advanced Topic: VECTOR OF VECTORS
    vector< vector<string> > allWords;
    //      ^^^^^^^^^^^^^^ -- You can make a vector of any type, including vectors!

    // A. Open the file
    fStrm.open( fName ); // Open file and Assign a file handle to `fStrm`

    if( fStrm.fail() ){ // If the file failed to open, print and do nothing
        cout << "Unable to open file: End program!" << endl;
    }else{ // else the file opened, do something
        // NOTE: `std::getline` and `std::cin.getline` are NOT THE SAME
        // NOTE: DON'T MIX `std::getline` and `cin >>`
        while( 
            getline( fStrm , lineStr ) // Assign line as string to `lineStr`
            // `getline` returns a reference to the input string if it succeeds
        ){
            cout << "Got line: " << lineStr << endl;
            vector<string> dividedLine = split_string( lineStr , sep );
            if( dividedLine.size() ){
                allWords.push_back(  dividedLine  );
            }
        } 
    }
    cout << endl << endl;

    vector<string> lineVec;
    for( int line_i = 0 ; line_i < allWords.size() ; line_i++ ){ // For each line
        lineVec = allWords[ line_i ]; // Copy vector at this index to `lineVec`
        cout << "Line " << line_i+1 << " has " << lineVec.size() << " words: ";
        print_vector( lineVec );
    }

    fStrm.close(); // ALWAYS close the file


    return 0;
}

