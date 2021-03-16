#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

pair<string, vector<string>> parse(string l){
  stringstream s(l);
  vector<string> o2;
  string o1;

  string tmp;
  s >> tmp;
  do{
    o2.push_back(tmp);
    s >> tmp;
  } while(tmp != "->");
  s >> o1;
  return pair<string, vector<string>>(o1, o2);
}

unsigned short int comp(string in, map<string, vector<string>>& rules, map<string, unsigned short int>& urules){
  if(urules.count(in)) return urules[in];
  vector<unsigned short int> operands;
  unsigned short int out = 0;
  for(auto x : rules[in]){
    if(x[0] <= '9'){
      stringstream s(x);
      unsigned short int t;
      s >> t;
      operands.push_back(t);
    } else if(x[0] <= 'Z') {
      continue;
    } else {
      operands.push_back(comp(x, rules, urules));
    }
  }
  if(rules[in].size() == 1) out = operands[0];
  if(rules[in].size() == 2) out = ~operands[0];
  if(rules[in].size() == 3){
    if(rules[in][1] == "AND") out = operands[0] & operands[1];
    if(rules[in][1] == "OR") out = operands[0] | operands[1];
    if(rules[in][1] == "LSHIFT") out = operands[0] << operands[1];
    if(rules[in][1] == "RSHIFT") out = operands[0] >> operands[1];
  }
  urules[in] = out;
  return out;
}

int main(){
  map<string, vector<string>> rules;
  map<string, unsigned short int> urules;
  map<string, unsigned short int> rules2;

  ifstream f("input");
  string l;

  while(getline(f,l)) rules.insert(parse(l));

  rules2["b"] = comp("a", rules, urules);

  cout << rules2["b"] << endl;

  cout << comp("a", rules, rules2) << endl;

  return 0;
}

    
