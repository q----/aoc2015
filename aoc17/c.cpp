#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> p(int i){
  vector<int> out;
  for(int x = 0; pow(2,x) < i; x++){
    if((int)(i / pow(2,x)) % 2) out.push_back(x);
  }
  return out;
}

int main(){
  ifstream f("input");
  string l;
  vector<int> cups;
  while(getline(f,l)){
    int x;
    stringstream s(l);
    s >> x;
    cups.push_back(x);
  }
  int count = 0;
  int count2 = 0;
  int min = 100;

  for(int i = 0; i < pow(2, cups.size()); i++){
    int t = 0;
    vector<int> s = p(i);
    for(int a : s) t += cups[a];
    if(t == 150){
      count++;
      if(s.size() < min){
        count2 = 0;
	min = s.size();
      }
      if(s.size() == min) count2++;
    }
  }

  cout << count << endl;
  cout << count2 << endl;

  return 0;
}
