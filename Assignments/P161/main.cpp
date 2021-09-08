#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

/**
* Alex Trampert
* 4883 Programming Techniques
* 9/7/2021
**/

int main() {
  //Declaring variables to run loops/store data
  vector<int> lights;
  int val;
  int count = 0;
  bool moreValues = true;
  int time = 0;

  //Read initial value for starting check
  cin >> val;

  //Loop for each set of data and check for 3 0s
  while(count < 3) {

    if(val != 0) {
      //Reading in the values for each data set
      while(moreValues) {
        //If not 0, add value to vector
        if(val != 0) {
          lights.push_back(val);
          cin >> val;
        }
        //If 0, means end of input for set
        else {
          moreValues = false;
          //Reset 0 counter
          count = 0;
        }
      }

      //Calculate the time at which all lights sync up or fail to
      int min = *min_element(lights.begin(), lights.end()) - 5;
      for(int i = min; i <= 18000; i++) {
        int total = 0;
        for(int j = 0; j < lights.size(); j++) {
          if(i % (2 * lights[j]) < lights[j] - 5)
            total++;
          else 
            break;
        }

        //Comparing time, if good, then print the time
        time = i;
        if(total == lights.size()) {
          cout << setw(2) << setfill('0') << time/3600 << ':' 
               << setw(2) << setfill('0') << (time/60)%60 << ':' 
               << setw(2) << setfill('0') << time%60 << '\n';

          break;
        }

        //Otherwise print the failed to synchronize message
        if (time >= 18000)
            cout << "Signals fail to synchronise in 5 hours\n";
      }
      //Only prints values to ensure they are correct
      /*for (int i = 0; i < lights.size(); i++) {
        cout << lights[i] << " ";
      }
      cout << '\n';*/
    }

    //If 0, add to counter to check end of data sets
    if(val == 0) {
      count++;
    }

    //Read next value to begin next loop
    cin >> val;

    //Reset inner bool/vector to run again if more data
    moreValues = true;
    lights.clear();
  }
  //Extra line since UVa is needy
  cout << '\n';
  return 0;
}