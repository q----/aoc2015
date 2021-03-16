#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct r{
  string n;
  int x, y, z;
  int l = 0;
  int s = 0;
  r(string a, int b, int c, int d){
    n = a;
    x = b;
    y = c;
    z = d;
  }
};

r parse(string l){
  stringstream s(l);
  int x, y, z;
  string n, t;
  s >> n >> t >> t >> x >> t >> t >> y >> t >> t >> t >> t >> t >> t >> z;
  return r(n, x, y, z);
}

int main(){
  ifstream f("input");
  string l;
  int time = 2503;
  vector<r> team;
  while(getline(f,l)) team.push_back(parse(l));

  for(int t = 0; t < time; t++){
    int max = 0;
    for(int i = 0; i < team.size(); i++){
      if((t %(team[i].y + team[i].z)) < team[i].y){
	     team[i].l += team[i].x;
      }
      max = (team[i].l > max)? team[i].l: max;
    }
    for(int i = 0; i < team.size(); i++){
      if(team[i].l == max){
        team[i].s++;
      }
    }
  }

  int maxs = 0;
  int maxl = 0;

  for(r a : team){
    maxs = (maxs > a.s)? maxs:a.s;
    maxl = (maxl > a.l)? maxl:a.l;
  }

  cout << maxl << endl;
  cout << maxs << endl;

  return 0;
}
