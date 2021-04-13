#include <iostream>

using namespace std;

struct s{
  int h = 50;
  int m = 500;

  int bh = 51;
  int bd = 9;

  int s = 0;
  int p = 0;
  int r = 0;
};

int play(s g, int o, bool h);
int it(s g, int o, bool h);

int mi(s g, int o, bool h){
  if(g.m < 53) return 100000000;
  g.m -= 53;
  g.bh -= 4;
  if(g.bh <= 0) return 53 + o;
  return it(g, o+53, h);
}

int dr(s g, int o, bool h){
  if(g.m < 73) return 100000000;
  g.m -= 73;
  g.h += 2;
  g.bh -= 2;
  if(g.bh <= 0) return 73 + o;
  return it(g, o+73, h);
}

int sh(s g, int o, bool h){
  if(g.s != 0 || g.m < 113) return 100000000;
  g.m -= 113;
  g.s = 6;
  return it(g, o+113, h);
}

int po(s g, int o, bool h){
  if(g.p != 0 || g.m < 173) return 100000000;
  g.m -= 173;
  g.p = 6;
  return it(g, o+173, h);
}

int re(s g, int o, bool h){
  if(g.r != 0 || g.m < 229) return 100000000;
  g.m -= 229;
  g.r = 5;
  return it(g, o+229, h);
}

bool ef(s& g){
  if(g.p > 0){
    g.p--;
    g.bh -= 3;
  }
  if(g.r > 0){
    g.r--;
    g.m += 101;
  }
  if(g.s > 0){
    g.s--;
    return true;
  }
  return false;
}

int it(s g, int o, bool h){
  bool gu = ef(g);
  if(g.bh <= 0) return o;
  g.h -= (gu)?2:9;
  if(g.h <= 0) return 100000000;
  return play(g, o, h);
}

int play(s g, int o, bool h){
  if(h){
    g.h--;
    if(g.h <= 0) return 100000000;
  }
  ef(g);
  if(g.bh <= 0) return o;

  if(o > 2000) return 100000000;

  int min = mi(g, o, h);
  int tmp = dr(g, o, h);
  min = (min < tmp)?min:tmp;
  tmp = po(g, o, h);
  min = (min < tmp)?min:tmp;
  tmp = sh(g, o, h);
  min = (min < tmp)?min:tmp;
  tmp = re(g, o, h);
  min = (min < tmp)?min:tmp;

  return min;
}

int main(){
  s g;
  cout << play(g, 0, false) << endl;
  cout << play(g, 0, true) << endl;
  return 0;
}
