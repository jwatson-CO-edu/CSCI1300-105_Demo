#include <iostream>
#include <string>
using namespace std;

string numbers[2] = { "123" , "456.7" };

int main(){
    int n1 = stoi( numbers[0] );
    cout << "Interpret string as int:    " << n1 << endl;

    double n2 = stod( numbers[1] );
    cout << "Interpret string as double: " << n2 << endl;
    
}