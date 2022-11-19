#include <iostream>
#include <stdlib.h> 
#include <cstdlib>
#include <list>
using namespace std;

string told_exec(string prisoners[], string player, string pardoned){
  string out;
  string free[2];
  int num = 0;
  for (int i = 0; i<3; i++){
    if (prisoners[i] == player){
      continue;
    }
    else{
      free[num] = prisoners[i];
      num++;
    }
  }
  if (pardoned == player){
    int k = rand() % 2;
    out = free[k];
  }
  else{
    for (int i = 0; i<3;i++){
      if (prisoners[i] != pardoned && prisoners[i] != player){
        out = prisoners[i];
      }
    }
    }
  return out;  
}


string nplayer(string prisoners[3], string player, string told){
  string new_player;
  for (int i = 0; i<3;i++){
    if (prisoners[i] != told && prisoners[i] != player){
      new_player = prisoners[i];
    }
    }
  return new_player;
}

bool safe(string player, string pardoned){
  if (player == pardoned){
    return true;
  }
  else{
    return false;
  }  
}


int main(){
  cout << "Number of attemps";
  int x;
  cin >> x;
  string sum[x];
  string no_change[x];

  bool no_switch[x];
  bool switc[x];

  string player = "A";
  string prisoners[3] = {"A", "B", "C"};
  for (int i = 0; i<x; i++){
    int j = rand() % 3;
    string pardoned = prisoners[j];
    sum[i] = pardoned; 
    string told = told_exec(prisoners, player, pardoned);
    no_change[i] = told;

    no_switch[i] = safe(player, pardoned);
    switc[i] = safe(nplayer(prisoners, player, told), pardoned);

    player = nplayer(prisoners, player, pardoned);
  }

  double no_switch_count = 0;
  for (int i = 0; i<x; i++){
    if (no_switch[i] == true){
      no_switch_count++;
    }
  }

  double switch_count = 0;
  for (int i = 0; i<x; i++){
    if (switc[i] == true){
      switch_count++;
    }
  }

  cout << "Probablity of survival before switch = " << (no_switch_count/x) << endl;
 cout << "Probablity of survival after switch = " << (switch_count/x) << endl;
  
}