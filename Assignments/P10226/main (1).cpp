/**
* Alex Trampert
* 4883 Programming Techniques
* 9/21/2021
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
  int cases;

  //read in number of cases
  cin >> cases;

  //declare all variables
  string name;
  vector<string> trees;
  vector<double> amount;
  getline(cin, name);
  bool found = false;
  double total = 0;
  pair <string, int> treeStats;
  vector <pair <string, int>> stats;

  //loop for each case
  while(cases >= 0) {
    getline(cin, name);

    //if finds a blank line, end of case, do work
    if(name == "") {
      double tempVal = 0;
      string tempString = "";

      //convert the seperate arrays to one data set
      for(int i = 0; i < trees.size(); i++) {
        if(trees[i] != "")
          treeStats.first = trees[i];
          treeStats.second = amount[i];
          stats.push_back(treeStats);
      }

      //sort complete data set alphabetically
      bool change = true;
      while(change) {
        change = false;
        for(int i = 0; (i+1) < stats.size(); i++) {
          if(stats[i].first > stats[i+1].first){
            tempString = stats[i].first;
            tempVal = stats[i].second;
            stats[i] = stats[i+1];
            stats[i+1].first = tempString;
            stats[i+1].second = tempVal;
            change = true;
          }
        }
      }

      //print data with 4 decimal places
      for(int i = 0; i < stats.size(); i++) {
        if(stats[i].first != "")
          cout << stats[i].first << " " << fixed << setprecision(4) 
               << ((stats[i].second/total)*100) << '\n';
      }

      //clear data for next case
      if(trees.size() > 0)
        cout << '\n';
      trees.clear();
      amount.clear();
      stats.clear();
      total = 0;
      cases--;
    }

    else {
      //compare name to existing trees, if found, add 1 to its total
      for(int i = 0; i < trees.size(); i++)
        if(trees[i] == name) {
          amount[i]++;
          found = true;
        }
    
      //if the tree does not exist yet, add it to both vecotrs
      if(!found) {
        trees.push_back(name);
        amount.push_back(1);
      }

      //reset found and increment total trees for the case
      found = false;
      total++;
    }
  }
}