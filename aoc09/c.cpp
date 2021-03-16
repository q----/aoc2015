#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct route{
  string s;
  string e;

  route(string a, string b){
    s = (a < b)? a : b;
    e = (a > b)? a : b;
  }
};

bool operator<(const route& lhs, const route& rhs){
  if(lhs.s != rhs.s) return lhs.s < rhs.s;
  return lhs.e < rhs.e;
}

pair<route, int> parse(string l, set<string>& p){
  stringstream s(l);
  string tmp;
  string a, b;
  int le;
  s >> a >> tmp >> b >> tmp >> le;
  p.insert(a);
  p.insert(b);
  return pair<route, int>(route(a,b),le);
}

int len(vector<string> in, map<route, int>& w){
  int out = 0;
  for(int i = 0; i < in.size() - 1; i++){
    out += w[route(in[i],in[i+1])];
  }
  return out;
}

int main(){
  ifstream f("input");
  string l;
  map<route, int> graph;
  set<string> p;
  while(getline(f,l)) graph.insert(parse(l, p));
  
  vector<string> v(p.begin(), p.end());

  sort(v.begin(), v.end());
  
  int min = 1000000;
  int max = 0;

  do{
    int tmp = len(v, graph);
    min = (tmp < min)? tmp: min;
    max = (tmp > max)? tmp: max;
  } while(next_permutation(v.begin(), v.end()));

  cout << min << endl;
  cout << max << endl;

  return 0;
}
