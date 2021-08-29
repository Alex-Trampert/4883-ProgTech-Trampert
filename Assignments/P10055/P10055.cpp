#include <iostream>
#include <string>

/**
* Alex Trampert
* 4883 Programming Techniques
* 8/29/2021
*/

#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    long int B = 0, A = 0;
    
    while (cin >> A >> B) {
        
      if (A > B)
        cout << A - B << endl;  

      else
        cout << B - A << endl;  
    }

    return 0;
}