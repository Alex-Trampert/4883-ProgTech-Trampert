/**
* Alex Trampert
* 4883 Programming Techniques
* 9/21/2021
**/

#include <iostream>
using namespace std;

int main() {
  int val;
  cin >> val;
  long int temp1 = 0, temp2 = 1;

  //Compute fibonacci sequence of value
  while(val != 0) {
    long int patterns;
    for(int i = 0; i < val; i++) {
      patterns = temp1 + temp2; 
      temp1 = temp2;
      temp2 = patterns;
      //cout << "Loop " << i << " = " << patterns << '\n';
    }

    cout << patterns << '\n';
    cin >> val;
    temp1 = 0;
    temp2 = 1;
  }
  //cout << '\n';
}