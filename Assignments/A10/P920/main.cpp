/**
* Alex Trampert
* 4883 Programming Techniques
* 9/30/2021
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

struct point;

int c, N;
vector<point> points;
int x, y;

struct point{
  int x; 
  int y;
  point(): x{0}, y{0}{}
  point(int x, int y):x{x}, y{y}{}
};

bool cmp(point &a, point &b) {
  return a.x < b.x;
}

void printPoints() {
  for(int i = 0; i < points.size(); i++) {
    cout << "[" << points[i].x << "," << points[i].y << "] ";
  }
}

int main() {
  cin >> c;
  while(c--) {
    cin >> N;
    while(N--) {
      cin >> x >> y;
      points.push_back(point(x, y));
    }
    sort(points.begin(), points.end(), cmp);
    //printPoints();
    //cout << '\n';

    double sunny_len = 0;
    double hmax = 0;
    double sideX = 0;
    double slope = 0;
    double dist = 0, side = 0;
    for(int i = points.size()-1; i >= 0; i--) {
      if(points[i].y > hmax) {
        //cout << "[" << points[i].x << ", " << points[i].y << "] ";
        // slope = ((points[i+1].y-points[i].y)/(points[i+1].x-points[i].x));
        // cout << slope << " ";

        //Caculate X for the given Y
        sideX = (((hmax-points[i].y)*(points[i+1].x-points[i].x))
                /(points[i+1].y-points[i].y)) + points[i].x;
        //cout << sideX << " ";

        //Calculate distance using peak and new coordinate
        dist = sqrt(pow((points[i].x - sideX), 2) 
              + pow((points[i].y-hmax), 2));

        //yi = ((y2-y1)*(xi-x1)/(x2-x1))+y1
        //xi = ((yi-y1)*(x2-x1)/(y2-y1))+x1
        //cout << dist << "\n";

        //Sum lengths
        sunny_len += dist;
        hmax = points[i].y;
      }
    }

    cout << fixed << setprecision(2) << sunny_len << '\n';
    points.clear();
    //cout << '\n';
  }
}