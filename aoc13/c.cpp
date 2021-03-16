#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

pair<pair<string, string>, int> parse (string l, set<string>& peeps){
  stringstream s(l);
  string a, b, t, p;
  int x;
  s >> a >> t >> p >> x >> t >> t >> t >> t >> t >> t >> b;
  peeps.insert(a);
  x = (p == "gain")?x:-x;
  return pair<pair<string, string>, int> (pair<string,string>(a,b.substr(0,b.size()-1)), x);
}

int main(){
  ifstream f ("input");
  string l;
  map<pair<string,string>, int> hap;
  set<string> p;

  while(getline(f,l)) hap.insert(parse(l,p));

  vector<string> peeps (p.begin(), p.end());
  int max = 0;

  do{
    int tmp = 0;
    for(int i = 0; i < peeps.size(); i++){
      tmp += hap[pair<string,string>(peeps[i], peeps[(i+1)% peeps.size()])];
      tmp += hap[pair<string,string>(peeps[(i+1)% peeps.size()], peeps[i])];
    }
    max = (max > tmp)? max:tmp;
  }while(next_permutation(peeps.begin(), peeps.end()));

  cout << max << endl;

  peeps.push_back("Ben");
  sort(peeps.begin(), peeps.end());
  max = 0;

  do{
    int tmp = 0;
    for(int i = 0; i < peeps.size(); i++){
      tmp += hap[pair<string,string>(peeps[i], peeps[(i+1)% peeps.size()])];
      tmp += hap[pair<string,string>(peeps[(i+1)% peeps.size()], peeps[i])];
    }
    max = (max > tmp)? max:tmp;
  }while(next_permutation(peeps.begin(), peeps.end()));

  cout << max << endl;

  return 0;
}
