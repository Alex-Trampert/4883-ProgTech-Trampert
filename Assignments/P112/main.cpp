#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  char character = ' ';
  string tree;
  int goal, count = 0, index = 0;
  vector <int> numbers;
  bool found = false;
  int iteration = 0;

  while(cin >> goal){
    tree = "";
    //cout << goal << " ";
    while(character != '(')
      cin.get(character);
    tree += character;
    if(character == '(')
      count++;
    while(count) {
      cin.get(character);
      if((character != '\n') && (character != ' '))
        //cout << character;
        tree += character;
      if(character == '(')
        count++;
      else if(character == ')')
        count--;
    }
    //cout << tree << '\n';
    
    index = 0;
    string temp = "";
    int sum = 0;
    string leafTest = "";
    bool endLeaf = false;

    while(index < tree.size()) {
      if(tree[index] == '('){
        if(tree[index+1] == ')') {
          //do nothing
        }
        else{
          while(tree[index+1] != '(' && tree[index] != ')') {
            temp += tree[index+1];
            index++;
            //cout << "temp: " << temp << '\n';
          }
          numbers.push_back(stoi(temp));
          leafTest = "";
          for(int i = 1; i < 5; i++) {
            leafTest += tree[index+i];
          }
          //cout << "test: " << leafTest << '\n';
          if(leafTest == "()()") {
            endLeaf = true;
          }
          else
            endLeaf = false;
          //cout << "endLeaf: " << endLeaf << '\n';
          temp = "";
        }
      }
      else if(tree[index] == ')') {
       if(tree[index-1] == '(') {
         //do nothing
       }
       else{
         numbers.pop_back();
         endLeaf = false;
       }
      }

      for(int i = 0; i < numbers.size(); i++) {
        //cout << numbers[i] << " ";
        sum += numbers[i];
      }
      //cout << "sum: " << sum << '\n';
      if(sum == goal && endLeaf) {
        found = true;
        //cout << "found!\n";
      }
      //cout << '\n';
      index++;
      sum = 0;
    }

    if(found) {
      cout << "yes\n";
    }
    else {
      cout << "no\n";
    }

    numbers.clear();
    //cout << '\n';
    found = false;
    iteration++;
  }
}