#include <iostream>
using namespace std;

int main() {
  int val;
  while(cin >> val) {
    //BIG data type to hold the sum
    long long sum = 0;
    for(long long i = val; i > 0; i--) {
      //Sum the cube of all n values
      sum += (i * i * i);
    }

    cout << sum << '\n';
  }
} 