#include <iostream>
#include <fstream>

using namespace std;

int parse(string s){
  int out = 2;
  for(int i = 1; i < s.size() - 1; i++){
    if(s[i] == '\\'){
      out++;
      if(s[++i] == 'x'){
        out += 2;
	i += 2;
      }
    }
  }
  return out;
}

int parse2(string s){
  int out = 4;
  for(int i = 1; i < s.size() - 1; i++){
    if(s[i] == '\\' | s[i] == '"') out++;
  }
  return out;
}

int main(){
  ifstream f("input");
  string l;
  int tot = 0;
  int tot2 = 0;
  while(getline(f,l)){
    tot += parse(l);
    tot2 += parse2(l);
  }
  cout << tot << endl;
  cout << tot2 << endl;
  return 0;
}
