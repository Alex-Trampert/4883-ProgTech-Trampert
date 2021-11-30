#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> vv; //vector of vectors

int n; // number of vertices

//Make vectors for each junction holding connections
// 0 1          0 - 1
// 1 2          1 - 0, 2, 4
// 1 4    >>    2 - 1, 3
// 2 3          3 - 2, 4
// 3 4          4 - 1, 3
//Traverse main vector starting by making 0 covered (0)
//Everything connected to 0 is guarded(1)
//Go to first element not connected to 0 and make it covered(0)
//Continue with this until end of vector
//If any guarded(1) are connected to another guarded(1) return -1
//If not, count guarded(1) and covered(0) and return lowest value

int main(int argc, char **argv) {
  //T = sets, v = junctions, e = streets, s = streetBegin, t = streetEnd
  int T;
  int v, e;
  int s, t;
  int x = 1;
  vector<int> streets;

  cin >> T;
  bool impossible = false;
  bool done = false;

  while(T){
    //cout << "Set " << x << '\n';
    //get node and edge counts
    cin >> v >> e;
    vv junctions;
    streets.push_back(0);

    //Checks if there are no connections; if not guards = junctions
    if(e == 0) {
      cout << v << '\n';
      T--;
      done = true;
    }

    if(!done) {
      //creates my array of connections
      for (int i = 0; i < v; i++) {
        junctions.push_back(streets);
      }

      //read in edges 
      for (int i = 0; i < e; i++) {
        cin >> s >> t;
        //make each connection for each node - 2 way
        junctions[s].push_back(t);
        junctions[t].push_back(s);
      }

/*    //Printing just for testing reading the input
      for(int i = 0; i < junctions.size(); i++) {
        for(int j = 0; j < junctions[i].size(); j++) {
          cout << junctions[i][j] << ' ';
        }
        cout << '\n';
      }*/

      //Checking for what is guarded(1) and what is covered(0)
      //and updates to guarded(1) if connected to covered(0)
      for (int i = 0; i < junctions.size(); i++) {
        if(junctions[i][0] == 0) {
          for(int j = 1; j < junctions[i].size(); j++) {
            int temp = junctions[i][j];
            junctions[temp][0] = 1;
          }
        }
      }

      //Printing just for testing reading the input
      /*for(int i = 0; i < junctions.size(); i++) {
        for(int j = 0; j < junctions[i].size(); j++) {
          cout << junctions[i][j] << ' ';
        }
        cout << '\n';
      }*/

      //Checking overlapping guards
      for(int i = 0; i < junctions.size(); i++) {
        for(int j = 1; j < junctions[i].size(); j++) {
          //Ensuring checking proper junction
          int temp = junctions[i][j];
          if(junctions[i][0] == junctions[temp][0] == 1) {
            impossible = true;
            break;
          }
        }
      }

      int count1 = 0;
      int count0 = 0;
      int count = 0;

      //If impossible print -1 otherwise print value
      if (impossible)
        cout << -1 << '\n';
      else {
        //Counts number og guarded(1), covered(0), and isolated
        for(int i = 0; i < junctions.size(); i++) {
          if(junctions[i].size() == 1)
            count++;
          if(junctions[i][0] == 1)
            count1++;
          else
            count0++;
        }
        
        if(count0 <= count1) {
          if(count1 < count0)
            cout << count1 << '\n';
          else
            cout << count0 << '\n';
        }
        else {
          if(count1 < count0)
            cout << count1 + count << '\n';
          else
            cout << count0 + count << '\n';
        }
      }
      --T;
    }

    impossible = false;
    //cout << "=====================\n";
    junctions.clear();
    streets.clear();
    done = false;
    x++;
  }

  cout << '\n';
  return 0;
}