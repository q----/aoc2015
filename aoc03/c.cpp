#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct house{
  int x;
  int y;
  house(int a, int b){
    x = a;
    y = b;
  }
};

bool operator<(const house & lhs, const house & rhs){
  if(lhs.x != rhs.x) return (lhs.x < rhs.x);
  return lhs.y < rhs.y;
}

int main(){
  set<house> del;
  set<house> del2;
  ifstream f("input");
  string line;
  getline(f,line);

  house curr(0,0);
  del.insert(curr);
  del2.insert(curr);
  vector<house> team;
  team.push_back(curr);
  team.push_back(curr);

  for(char a : line){
    if(a == '^') curr.y++;
    if(a == 'v') curr.y--;
    if(a == '<') curr.x--;
    if(a == '>') curr.x++;
    del.insert(curr);
  }

  cout << del.size() << endl;

  for(int i = 0; i < line.size(); i++){
    if(line[i] == '^')team[i%2].y++;
    if(line[i] == 'v')team[i%2].y--;
    if(line[i] == '<')team[i%2].x--;
    if(line[i] == '>')team[i%2].x++;
    del2.insert(team[i%2]);
  }

  cout << del2.size() << endl;

  return 0;
}
