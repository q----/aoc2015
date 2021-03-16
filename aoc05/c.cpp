#include <iostream>
#include <fstream>
#include <set>

using namespace std;

bool vowels (string s, set<char> &vowel){
  int count = 0;
  for(char a : s){
    if(vowel.count(a)){
      if(++count >= 3) return true;
    }
  }
  return false;
}

bool dub(string s){
  for(int i = 0; i < s.size() - 1; i++){
    if(s[i] == s[i+1]) return true;
  }
  return false;
}

bool naughty(string s, set<string>& naug){
  for(int i = 0; i < s.size() - 1; i++){
    if(naug.count(s.substr(i,2))) return true;
  }
  return false;
}

bool dubrep(string s){
  for(int i = 0; i < s.size() - 3; i++){
    for(int j = i + 2; j < s.size() - 1; j++){
      if(s.substr(i,2) == s.substr(j,2)) return true;
    }
  }
  return false;
}

bool inrep(string s){
  for(int i = 0; i < s.size() - 2; i++){
    if(s[i] == s[i+2]) return true;
  }
  return false;
}

bool nice(string s, set<char> &vowel, set<string>& naug){
  bool v = vowels(s, vowel);
  bool d = dub(s);
  bool n = naughty(s, naug);
  return (v && d && !n);
}

bool nice2(string s){
  return (dubrep(s) && inrep(s));
}

int main(){
  string line;
  fstream f("input");
  set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  set<string> naug = {"ab", "cd", "pq", "xy"};

  int nic = 0;
  int nic2 = 0;

  while(getline(f, line)){
    if(nice(line, vowel, naug)) nic++;
    if(nice2(line)) nic2++;
  }

  cout << nic << endl;
  cout << nic2 << endl;

  return 0;
}

