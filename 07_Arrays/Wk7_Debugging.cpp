#include <iostream>
using namespace std;

bool _DB = 0;

int add_to( int x ){
    // Add 5 to the argument, and return
    int result = x;
    result += 2;  /*DEBUG:*/ if(_DB){  cerr << "result1: " << result << endl;  }
    result += 3;  /*DEBUG:*/ if(_DB){  cerr << "result2: " << result << endl;  }
    return result;
}

int subtract_from( int x ){
    // Subtract 30 from the argument, and return
    int result = x;
    result = result - 10;  /*DEBUG:*/ if(_DB){  cerr << "result3: " << result << endl;  }
    result = result - 20;  /*DEBUG:*/ if(_DB){  cerr << "result4: " << result << endl;  }
    return result;
}

int main(){
    
    int y   = 32 ,
        res =  0 ;
        
    res = add_to( y );
    cout << "First function test:  " << res << endl;
    res = subtract_from( y );
    cout << "Second function test: " << res << endl;
    
    return 0;
}