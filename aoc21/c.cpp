#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct lad{
  int h = 0;
  int d = 0;
  int a = 0;
  int c = 0;
  lad(int health, int damage, int armor, int cost = 0){
    h = health;
    d = damage;
    a = armor;
    c = cost;
  }
  lad(){}
};

lad operator+(const lad& lhs, const lad& rhs){
  return lad(lhs.h + rhs.h, lhs.d + rhs.d, lhs.a + rhs.a, lhs.c + rhs.c);
}

int ce(int x, int y){
  return x/y + (x % y != 0);
}

bool win(lad m, lad b, bool t = true){
  int md = m.d - b.a;
  if(md < 1) md = 1; 
  int bd = b.d - m.a;
  if(bd < 1) bd = 1; 
  return (ce(b.h,md) < ce(m.h,bd)) || (t && ce(b.h,md) == ce(m.h,bd));
}

lad parse(string l, bool ring = false){
  stringstream s (l);
  string x;
  lad out;
  if(ring) s >> x;
  s >> x >> out.c >> out.d >> out.a;
  return out;
}

int main(){
  ifstream f("input2");
  string l;
  vector<vector<lad>> shop;

  while(getline(f,l)){
    bool r = (l[0] == 'R');
    vector<lad> curr;
    while(getline(f,l) && l != "") curr.push_back(parse(l, r));
    shop.push_back(curr);
  }
  shop[1].push_back(lad(0,0,0));
  shop[2].push_back(lad(0,0,0));
  shop[2].push_back(lad(0,0,0));

  ifstream f2("input");
  getline(f2,l);
  stringstream s(l);
  string t;
  lad b;
  s >> t >> t >> b.h;
  getline(f2,l);
  s.str("");
  s.clear();
  s << l;
  s >> t >> b.d;
  getline(f2,l);
  s.str("");
  s.clear();
  s << l;
  s >> t >> b.a;
  
  lad m = lad(100,0,0);
  
  int min = 10000;
  int max = 0;
  for(lad a : shop[0]){
    for(lad c : shop[1]){
      for(int i = 0; i < shop[2].size() - 1; i++){
        for(int j = i; j < shop[2].size(); j++){
          lad curr = m + a + c + shop[2][i] + shop[2][j];
	  if(win(curr,b)) min = (curr.c < min)? curr.c:min;
	  if(win(b,curr,false)) max = (curr.c > max)? curr.c:max;
	}
      }
    }
  }

  cout << min << endl;
  cout << max << endl;

  return 0;
}

