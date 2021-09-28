/**
* Alex Trampert
* 4883 Programming Techniques
* 9/28/2021
**/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  //M = Dictionary entries; N = Job Descriptions
  int m, n;
  cin >> m >> n;
  pair <string, int> term;
  vector <pair<string, int>> dictionary;
  string temp;
  vector <string> description;
  int salary = 0;

  //Loop for all entries in dictionary
  for(int i = 0; i < m; i++) {
    cin >> term.first >> term.second;
    dictionary.push_back(term);
  }

  // for(int i = 0; i < dictionary.size(); i++) {
  //   cout << dictionary[i].first << " " << dictionary[i].second << '\n';
  // }

  //Loop for n job descriptions
  for(int term = 0; term < n; term++) {
    cin >> temp;

    //Create vector of the description so each word is stored seperately
    while(temp != ".") {
      description.push_back(temp);
      cin >> temp;
    }

    //Compare each word in description to the words in dictionary/tally salary
    for(int i = 0; i < description.size(); i++) {
      for(int j = 0; j < dictionary.size(); j++) {
        if(description[i] == dictionary[j].first) {
          salary += dictionary[j].second;
        }
      } 
    }

    cout << salary << '\n';

    description.clear();
    salary = 0;
  }
}