#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct team{
  string name;
  int games = 0, wins = 0, ties = 0, losses = 0;
  int goals = 0, against = 0;
  int points = 0;
};

int main() {
  int cases, teams, games;
  string tournament, name, data;
  vector<team> teamData;
  vector<string> gameData;
  
  //Read in number of cases
  cin >> cases;

  cin.ignore();
  while(cases) {
    team tempTeam;
    //Read in tournament name
    getline(cin, tournament);
    cout << tournament << '\n';
    
    //Read in team names and make teams
    cin >> teams;
    cin.ignore();
    for(int i = 0; i < teams; i++) {
      getline(cin, name);
      tempTeam.name = name;
      teamData.push_back(tempTeam);
    }

    //Read in game data
    cin >> games;    
    cin.ignore();
    for(int i = 0; i < games; i++) {
      getline(cin, data);
      gameData.push_back(data);
    }

    //Breaking up the game data to work with and calculate goals/points/etc
    string name1 = "", name2 = "", points1 = "", points2 = "";
    bool check1, check2, check3;
    int count = 0;
    for(int i = 0; i < gameData.size(); i++) {
        while (gameData[i][count] != '#') {
          name1 += gameData[i][count];
          count++;
        }
        count++;
        while(gameData[i][count] != '@') {
          points1 += gameData[i][count];
          count++;
        }
        count++;
        while (gameData[i][count] != '#') {
          points2 += gameData[i][count];
          count++;
        }   
        count++; 
        while (count < gameData[i].size()) {
          name2 += gameData[i][count];
          count++;
        }

        //Tallies all data for all elements
        for(int j = 0; j < teamData.size(); j++) {
          if(teamData[j].name == name1){
            teamData[j].games++;
            teamData[j].goals += stoi(points1);
            teamData[j].against += stoi(points2);
            if(points1 < points2)
              teamData[j].losses++;
            else if(points1 > points2) {
              teamData[j].wins++;
              teamData[j].points += 3;
            }
            else {
              teamData[j].ties++;
              teamData[j].points += 1;
            }
          }
          else if(teamData[j].name == name2){
            teamData[j].games++;
            teamData[j].goals += stoi(points2);
            teamData[j].against += stoi(points1);
            if(points2 < points1)
              teamData[j].losses++;
            else if(points2 > points1) {
              teamData[j].wins++;
              teamData[j].points += 3;
            }
            else {
              teamData[j].ties++;
              teamData[j].points += 1;
            }
          }
        }
        name1 = name2 = points1 = points2 = "";
        count = 0;
    }

    //Attempting to sort
    bool change = true;
    while(change) {  
      change = false;
      for(int i = 0; (i + 1) < teamData.size(); i++) {
        //If points[i] < points[i+1] swap
        if(teamData[i].points < teamData[i+1].points) {
          tempTeam = teamData[i+1];
          teamData[i+1] = teamData[i];
          teamData[i] = tempTeam;
          change = true;
          //cout << "points";
        }
        //If equal check next
        else if(teamData[i].points == teamData[i+1].points) {
          //If wins[i] < wins[i+1] swap
          if(teamData[i].wins < teamData[i+1].wins) {
            tempTeam = teamData[i+1];
            teamData[i+1] = teamData[i];
            teamData[i] = tempTeam;
            change = true;
            //cout << "wins";
          }
          //If equal check next
          else if(teamData[i].wins == teamData[i+1].wins) {
            //If goalDif[i] < goalDif[i+1] swap
            if((teamData[i].goals-teamData[i].against) < 
              (teamData[i+1].goals-teamData[i+1].against)) {
              tempTeam = teamData[i+1];
              teamData[i+1] = teamData[i];
              teamData[i] = tempTeam;
              change = true;
              //cout << "gd";
            }
            //If equal check next
            else if((teamData[i].goals-teamData[i].against) == 
                   (teamData[i+1].goals-teamData[i+1].against)) {
              //If goals[i] < goals[i+1] swap
              if(teamData[i].goals < teamData[i+1].goals) {
                tempTeam = teamData[i+1];
                teamData[i+1] = teamData[i];
                teamData[i] = tempTeam;
                change = true;
                //cout << "goals";
              }
              //If equal check next
              else if(teamData[i].goals == teamData[i+1].goals) {
                //If games[i] > games[i+1] swap
                if(teamData[i].games > teamData[i+1].games) {
                  tempTeam = teamData[i+1];
                  teamData[i+1] = teamData[i];
                  teamData[i] = tempTeam;
                  change = true;
                  //cout << "games";
                }
                //If equal check next
                else if(teamData[i].games == teamData[i+1].games) {
                  //If name[i] < name[i+1] swap
                  string tempName1, tempName2;
                  tempName1 = teamData[i].name;
                  tempName2 = teamData[i+1].name;
                  tempName1[0] = tolower(teamData[i].name[0]);
                  tempName2[0] = tolower(teamData[i+1].name[0]);
                  if(tempName1 > tempName2) {
                    tempTeam = teamData[i+1];
                    teamData[i+1] = teamData[i];
                    teamData[i] = tempTeam;
                    change = true;
                    //cout << "name";
                  }
                }
              }
            }
          }
        }
      }
    }

    //Print out all team data
    for(int i = 0; i < teamData.size(); i++) {
      cout << (i + 1) << ") ";
      cout << teamData[i].name << " " << teamData[i].points 
           << "p, " << teamData[i].games << "g (" 
           << teamData[i].wins << '-' <<teamData[i].ties << '-' << teamData[i].losses 
           << "), " << (teamData[i].goals-teamData[i].against) 
           << "gd (" << teamData[i].goals << "-" << teamData[i].against << ")\n";
    }

    if(cases > 1)
      cout << '\n';
    cases--;
    gameData.clear();
    teamData.clear();
  }
}