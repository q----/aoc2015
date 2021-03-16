#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
  ifstream f("input");
  string l;

  getline(f,l);

  string l2 = l;

  for(int i = 0; i < l.size(); i++){
    if(l[i] < '-' | l[i] > '9') l[i] = ' ';
  }

  stringstream s(l);
  int x;
  int out = 0;
  while(s >> x){
    out += x;
    x = 0;
  }

  cout << out << endl;

  int d = l2.find(":\"red\"");
  while(d != string::npos){
    int st = d;
    int c = 1;
    while(c > 0){
      st--;
      if(l2[st] == '}')c++;
      if(l2[st] == '{')c--;
    }
    int e = d;
    c = -1;
    while(c < 0){
      e++;
      if(l2[e] == '}')c++;
      if(l2[e] == '{')c--;
    }
    l2.erase(l2.begin()+ st + 1, l2.begin() + e);
    d = l2.find(":\"red\"");
  }

  for(int i = 0; i < l2.size(); i++){
    if(l2[i] < '-' | l2[i] > '9') l2[i] = ' ';
  }

  stringstream s2(l2);
  int x2;
  out = 0;
  while(s2 >> x2){
    out += x2;
    x2 = 0;
  }

  cout << out << endl;

  return 0;
}
