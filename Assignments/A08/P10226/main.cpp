/**
* Alex Trampert
* 4883 Programming Techniques
* 9/21/2021
**/

#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;

int main() {
  int cases;
  double total = 0;
  string name;
  map <string, double> trees;

  //Read in cases and initial blank line
  cin >> cases;
  getline(cin, name);
  cin.ignore();

  while(cases > 0) {
    while(getline(cin, name)) {
      if(name != ""){
        total++;
        //Search for name, if present increase value
        //If not present, insert it
        map<string, double>::iterator it = trees.find(name); 
        if (it == trees.end()) {
          trees.insert(pair <string, double> (name, 1));
        } else {
          it->second++;
        }
      }
      else
        break;
    }

    //Print the key and the calculated percentage
    map<string, double>::iterator itr;
    for(itr = trees.begin(); itr != trees.end(); ++itr) {
      cout << itr->first << " " << fixed << setprecision(4) 
           << ((itr->second/total) * 100) << '\n';
    }

    //Reset all values for next case
    cases--;
    total = 0;
    trees.clear();
    //Prints obnoxious blank line after every case except the last
    //because online judge is PICKY
    if(cases > 0)
      cout << '\n';
  }
}