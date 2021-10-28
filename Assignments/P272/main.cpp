#include <iostream>
using namespace std;

int main() {
  char character;
  int count = 0;
  while(cin >> noskipws >> character) {
    //If first " print `` instead
    if (character == '"' && (count % 2) == 0) {
      cout << "``";
      count++;
    }
    //If second " print '' instead
    else if (character == '"' && (count % 2) == 1) {
      cout << "''";
      count++;
    }
    //Anything else - print directly
    else 
      cout << character;
  }
} 