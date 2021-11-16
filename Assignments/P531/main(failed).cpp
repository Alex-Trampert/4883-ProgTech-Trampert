//THIS IS NOT THE CORRECT ANSWER
//THIS WAS TAKE 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <string> string1;
  vector <string> string2;
  vector <string> compromise;
  string word;
  int index;

  while(cin >> word) {
    if(word != "#")
      string1.push_back(word);
    //Read string 1
    while(cin >> word) {
      if(word != "#")
        string1.push_back(word);
      else
        break;
    }
    //Read string 2
    while(cin >> word) {
      if(word != "#")
        string2.push_back(word);
      else
        break;
    }

    cout << "\nString 1:\n";
    for(int i = 0; i < string1.size(); i++) {
      cout << string1[i] << ' ';
    }

    cout << "\nString 2:\n";
    for(int i = 0; i < string2.size(); i++) {
      cout << string2[i] << ' ';
    }

    //For each word in string 1, cycle through string 2
    //If same word is found in string 2 - add to comp and set index at word
    //Continue with next word in string 1 starting from index in string 2
    //When the end of string 2 is reached - done
    index = 0;
    for(int i = 0; i < string1.size(); i++) {
      for(int j = 0; j < string2.size(); j++) {
        if(j < index)
          j = index;
        if(string1[i] == string2[j]) {
          index = j;
          compromise.push_back(string1[i]);
          break;
        }
      }
    }

    cout << "\nCompromise:\n";
    for(int i = 0; i < compromise.size(); i++) {
      cout << compromise[i] << ' ';
    }

    string1.clear();
    string2.clear();
    compromise.clear();
  }
} 
