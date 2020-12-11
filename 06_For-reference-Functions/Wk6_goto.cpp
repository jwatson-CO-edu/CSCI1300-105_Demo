#include <iostream>
using namespace std;

int main(){

    int i = 0;

    // NEVER do this
    loopTop:
        cout << i << ", ";
        i++;
    if( i < 5 ){  goto loopTop;  }
    cout << endl;
}