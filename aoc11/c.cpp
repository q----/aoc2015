#include <iostream>
#include <set>

using namespace std;

string inc(string s, int p){
  if(s[p] == 'z'){
    s[p] = 'a';
    return(inc(s,p-1));
  }
  s[p]++;
  set<char> avo = {'i','l','o'};
  if(avo.count(s[p]))s[p]++;
  return s;
}

string inc(string s){
  return inc(s, s.size() - 1);
}

bool dub(string s){
  for(int i = 0; i < s.size() - 3; i++){
    if(s[i] == s[i+1]){
      for(int j = i+2; j < s.size() - 1; j++){
        if(s[j] == s[j+1]) return true;
      }
      return false;
    }
  }
  return false;
}
      
bool in(string s){
  for(int i = 0; i < s.size() - 2; i++){
    if((s[i]+1 == s[i+1]) && (s[i+1] + 1 == s[i+2])) return true;
  }
  return false;
}

bool v(string s){
  return dub(s) && in(s);
}

int main(){
  string input = "hepxcrrq";

  do{
    input = inc(input);
  } while(!v(input));

  cout << input << endl;
  
  do{
    input = inc(input);
  } while(!v(input));

  cout << input << endl;
  
  return 0;
}
