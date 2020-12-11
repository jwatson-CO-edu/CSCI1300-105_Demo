// g++ -std=c++11 Wk13_Mystery.cpp

#include <iostream>
#include <string>
using namespace std;

int    rep    = 2 , // -- Number of spacer lines to print
       depth  = 1;
string prefix = ""; // - String to control indent at each depth of recursion
char   tab    = '\t'; // Character to prepend to prints at each greater depth of recursion

int mystery( int a ){
    /* Printing .. */ cout << prefix << "### Enter `mystery` with a = " << a 
    /* Printing .. */      << ", Depth = " << depth << " ###" << endl;
    /* Printing .. */ for(int i=0; i<rep; i++){  cout<<prefix<<"."<<endl;  }
    int val;
    if (a <= 0){
        /* Printing .. */ cout << prefix << ". Base Case" <<  endl;
        val = 1;
    }else{
        /* Printing .. */ cout << prefix << ". Recursive Case\n" << prefix << "." <<  endl;
        /* Printing .. */ prefix += tab;  depth++; // Indent at greater recursive depth
        val = a + mystery(a - 2);
        /* Printing .. */ prefix = prefix.substr(0,prefix.length()-1);  depth--;// Decrease indent
    }
    /* Printing .. */ for(int i=0; i<rep; i++){  cout<<prefix<<"."<<endl;  }
    /* Printing .. */ cout << prefix << "___ `mystery` returned with val = " << val 
    /* Printing .. */      << ", Depth = " << depth << " ___" << endl;
    return val;
}

int main(){
    int rslt = mystery(4);
    cout << "\nRESULT: " << rslt << endl;
    return 0;
}

// g++ -std=c++11 Wk13_Mystery.cpp