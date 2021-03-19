#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

pair<string,int> parse(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] == ':') l[i] = ' ';
  stringstream s(l);
  string a;
  int b;
  s >> a >> b;
  return pair<string,int> (a,b);
}

int main(){
  ifstream f("input");
  string l;

  map<string, int> m;

  while(getline(f,l)) m.insert(parse(l));

  ifstream f2("input2");
  int aout;
  int bout;

  while(getline(f2,l)){
    for(int i = 0; i < l.size(); i++) if(l[i] == ',' || l[i] == ':') l[i] = ' ';
    stringstream s(l);
    string t;
    int n;
    bool a = true;
    bool b = true;
    s >> t >> n;
    while(s >> t){
      int x;
      s >> x;
      if((t == "cats" || t == "trees") && m[t] >= x) b = false;
      if((t == "pomeranians" || t == "goldfish") && m[t] <= x) b = false;
      if(t != "cats" && t != "trees" && t != "pomeranians" && t != "goldfish" && m[t] != x) b = false;
      if(m[t] != x) a = false;
    }
    if (a) aout = n;
    if (b) bout = n;
  }

  cout << aout << endl;
  cout << bout << endl;

  return 0;
}
