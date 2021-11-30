//THIS IS THE WORKING AND CORRECT VERSION

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void compromise(vector <string> S1, vector <string> S2, int m, int n) {
  int lcsTable[m + 1][n + 1];

  //Calculating all values for the matrix
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      //If outer row/col value is 0
      if (i == 0 || j == 0)
        lcsTable[i][j] = 0;
      //If index for row/col same value is diagonal + 1
      else if (S1[i - 1] == S2[j - 1])
        lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
      //If index for row/col not same value is max value in matrix
      else
        lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
    }
  }

  int index = lcsTable[m][n];
  vector <string> subSeq;

  int i = m, j = n;
  while (i > 0 && j > 0) {
    //Follow values/arrows to build the common subsequence backwards
    if (S1[i - 1] == S2[j - 1]) {
      subSeq.push_back(S1[i - 1]);
      i--;
      j--;
      index--;
    }
    else if (lcsTable[i - 1][j] > lcsTable[i][j - 1])
      i--;
    else
      j--;
  }
  
  //Print the compromise
  for(int i = subSeq.size() - 1; i >= 0; i--) {
    cout << subSeq[i];
    if(i != 0)
      cout << " ";
  }
  cout << '\n';
}

int main() {
  vector <string> S1;
  vector <string> S2;
  string word;

  while(cin >> word) {
    if(word != "#")
      S1.push_back(word);
    //Read string 1
    while(cin >> word) {
      if(word != "#")
        S1.push_back(word);
      else
        break;
    }
    //Read string 2
    while(cin >> word) {
      if(word != "#")
        S2.push_back(word);
      else
        break;
    }

    int m = S1.size();
    int n = S2.size();

    compromise(S1, S2, m, n);

    S1.clear();
    S2.clear();
  }
} 