#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int operator+(const vector<int>& lhs, const vector<int>& rhs){
  int out = 0;
  for(int a : rhs){
    out += lhs[a];
  }
    
  return out;
}

long long int operator*(const vector<int>& lhs, const vector<int>& rhs){
  long long int out = 1;
  for(int a : rhs) out *= lhs[a];
  return out;
}

vector<int> con(int a){
  vector<int> out;
  for(int i = 0; i < a; i++) out.push_back(i);
  return out;
}

vector<int> next(vector<int> in, int s){
  if(in.size() == 0) return in;
  in[in.size()-1]++;
  if(*(in.end()-1) == s){
    in.erase(in.end()-1);
    in = next(in, s-1);
    if(in.size() == 0) return in;
    in.push_back(*(in.end()-1)+1);
  }
  return in;
}

long long int play(int q, vector<int> p){
  bool flag = true;
  long long int a = 999999999999999;
  int s = 0;

  while(flag){
    vector<int> t = con(++s);
    while(t.size() > 0){
      if(p + t == q){
        long long int x = p*t;
        a = (a < x)? a:x;
	flag = false;
      }
      t = next(t,p.size());
    }
  }

  return a;
}

int main(){
  ifstream f("input");
  string l;
  vector<int> p;
  int q = 0;

  while(getline(f,l)){
    stringstream s(l);
    int x;
    s >> x;
    q+=x;

    p.push_back(x);
  }

  cout << play(q/3, p) << endl;
  cout << play(q/4, p) << endl;

  return 0;
}
