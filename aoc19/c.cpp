#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

pair<string, string> parse(string l){
  string a, b;
  stringstream s (l);
  s >> a >> b >> b;
  return pair<string, string> (b,a);
}

set<string> sub (string l, pair<string, string> sub){
  set<string> out;
  for(int i = l.find(sub.second); i != string::npos; i = l.find(sub.second, i+1)){
    string s = l;
    s.replace(i,sub.second.size(), sub.first);
    out.insert(s);
  }
  return out;
}

int ce (string l){
  int out = 0;
  for(char a : l) if(a <= 'Z' || a == 'e') out++;
  return out;
}

int main(){
  ifstream f ("input");
  string l;
  map<string, string> lol;

  while(getline(f,l) && l != "") lol.insert(parse(l));
  getline(f,l);

  set<string> list;
  for(auto a : lol) for(string s : sub(l,a)) list.insert(s);
  cout << list.size() << endl;

  vector<string> subs;
  
  for(auto a : lol){
    auto i = subs.begin();
    for(i; i < subs.end(); i++){
      if(ce(*i) <= ce(a.first)) break;
    }
    subs.insert(i, a.first);
  }

  int count = 0;

  while(l != "e"){
    for(string s: subs){
      set<string> tmp = sub(l, pair<string, string>(lol[s], s));
      if(tmp.size()){
        l = *(tmp.begin());
	count++;
	break;
      }
    }
  }

  cout << count << endl;

  return 0;
}
