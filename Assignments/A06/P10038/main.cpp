#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
* Alex Trampert
* 4883 Programming Techniques
* 9/9/2021
**/

int main() {
  //Declaring variables
  vector<int> values;
  vector<int> checks;
  int n;
  int val;

  //Loops for each data set
  while(cin >> n) {
    //Clears data for each new set
    values.clear();
    checks.clear();

    //Reading in data values
    for(int i = 0; i < n; i++) {
      cin >> val;
      values.push_back(val);
      checks.push_back(0);
    }

    //Setting [0] to 1 for ease later
    checks[0] = 1;
    int temp;

    //Checks 2 values difference, changes that difference value
    //in checks to a 1 to 'mark it off'
    for(int i = 0; i < n - 1; i++) {
      temp = abs(values[i+1] - values[i]);
      if(temp > 0 && temp < n)
        checks[temp] = 1;
    }

    //Checking for all 1's, if it finds a 0 > Not jolly
    for(int i = 0; i < checks.size(); i++) {
      if(checks[i] == 0) {
        cout << "Not jolly\n";
        break;
      }

      else if(i == (checks.size() - 1))
        cout << "Jolly\n";
    }
  }
}