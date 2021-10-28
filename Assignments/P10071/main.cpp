#include <iostream>
using namespace std;

int main() {
  int time, velocity;
  while(cin >> time >> velocity) {
    //Double the time value
    time = time * 2;
    //Calculate distance
    velocity = (velocity* time);
    cout << velocity << '\n';
  }
}