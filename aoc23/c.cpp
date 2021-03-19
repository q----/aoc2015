#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct c{
  int pc = 0;
  vector<unsigned int> r = {0,0};
};

c n(c o, vector<string> inst){
  stringstream s(inst[o.pc]);
  string op;
  s >> op;
  if(op == "inc"){
    o.pc++;
    string x;
    s >> x;
    o.r[x[0]-'a']++;
  } else if(op == "tpl") {
    o.pc++;
    string x;
    s >> x;
    o.r[x[0]-'a'] *= 3;
  } else if(op == "hlf") {
    o.pc++;
    string x;
    s >> x;
    o.r[x[0]-'a'] /= 2;
  } else if(op == "jmp"){
    int x;
    s >> x;
    o.pc += x;
  } else if(op == "jie"){
    int x;
    string l;
    s >> l >> x;
    if(!(o.r[l[0]-'a'] % 2)) o.pc += x - 1;
    o.pc++;
  } else if(op == "jio"){
    int x;
    string l;
    s >> l >> x;
    if(o.r[l[0]-'a'] == 1) o.pc += x - 1;
    o.pc++;
  }
  return o;
}

int main(){
  ifstream f("input");
  string l;
  vector<string> inst;

  while(getline(f,l))inst.push_back(l);

  c o;

  while(o.pc >= 0 && o.pc < inst.size()) o = n(o, inst);

  cout << o.r[1] << endl;

  c o2;
  o2.r[0]++;

  while(o2.pc >= 0 && o2.pc < inst.size()) o2 = n(o2, inst);

  cout << o2.r[1] << endl;

  return 0;
}  

