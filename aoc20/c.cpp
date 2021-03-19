#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int sum(set<int> in){
  int out = 0;
  for(int a : in) out += a;
  return out;
}

int pro(set<int> in){
  int out = 1;
  for(int a: in) out *= a;
  return out;
}

set<int> factor(int in){
  set<int> out;
  for(int i = 1; i <= pow(in, 0.5); i++){
    if(!(in % i)){
      out.insert(i);
      out.insert(in/i);
    }
  }
  return out;
}

set<int> sfa(int in){
  set<int> out;
  for(int i = 1; i <= 50; i++){
    if(!(in % i)) out.insert(in/i);
  }
  return out;
}

int main(){
  int goal = 33100000;
  goal /= 10;

  int start = 770000;
  int i = start;

  while(++i) {
    if(sum(factor(i)) >= goal) break;
  }

  cout << i << endl;

  i = 1;
  goal *= 10;
  goal /= 11;

  while(++i) if(sum(sfa(i)) >= goal) break;

  cout << i << endl;

  return 0;
}

