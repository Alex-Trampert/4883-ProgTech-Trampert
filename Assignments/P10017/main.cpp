#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int steps, temp;
int stepsTaken;
vector <int> source;
vector <int> destination;
vector <int> intermediate;

void solve(int count, char source, char destination, char intermediate, vector <int> &sourceVec, vector <int> &destVec, vector <int> &intVec) {
  if (count == 1) {
    if(steps == 0) 
      return;
    if(source == 'A') {
      temp = sourceVec[sourceVec.size() - 1];
      sourceVec.pop_back();
    }
    else if(source == 'B') {
      temp = intVec[intVec.size() - 1];
      intVec.pop_back();
    }
    else if(source == 'C') {
      temp = destVec[destVec.size() - 1];
      destVec.pop_back();
    }

    if(destination == 'A')
      sourceVec.push_back(temp);
    else if(destination == 'B')
      intVec.push_back(temp);
    else if(destination == 'C')
      destVec.push_back(temp);

    cout << "A=>";
    for(int i = sourceVec.size(); i > 0; i--) {
      if(i == sourceVec.size())
        cout << "  ";
      cout << ' ' << sourceVec[sourceVec.size() - i];
    }
    cout << "\nB=>";
    for(int i = intVec.size(); i > 0; i--) {
      if(i == intVec.size())
        cout << "  ";
      cout << ' ' << intVec[intVec.size() - i];
    }
    cout << "\nC=>";
    for(int i = destVec.size(); i > 0; i--) {
      if(i == destVec.size())
        cout << "  ";
      cout << ' ' << destVec[destVec.size() - i];
    }
    steps--;
    stepsTaken++;
    cout << "\n\n";
  }
  else {
    if (steps != 0) {
      solve(count-1, source, intermediate, destination, sourceVec, destVec, intVec);
      solve(1, source, destination, intermediate, sourceVec, destVec, intVec);
      solve(count-1, intermediate, destination, source, sourceVec, destVec, intVec);
    }
  }
}

int main() {
  int discs;
  int probNum = 1;
  stepsTaken = 0;
  cin >> discs >> steps;

  while (discs != 0 && steps != 0) {
    cout << "Problem #" << probNum << "\n\n";
    cout << "A=>";
    for(int i = discs; i > 0; i--) {
      source.push_back(i);
      if(i == discs)
        cout << "  ";
      cout << ' ' << source[discs - i];
    }
    cout << '\n' << "B=>" << '\n' << "C=>" << "\n\n";
    solve(discs, 'A', 'C', 'B', source, destination, intermediate); 

    cin >> discs >> steps;
    stepsTaken = 0;
    probNum++;
    source.clear();
    intermediate.clear();
    destination.clear();
  }
} 