#include <iostream>

using namespace std;

string next(string s){
  string out = "";
  int x = 0;
  char a = s[0];
  for(char c : s){
    if(c != a){
      out += to_string(x) + a;
      a = c;
      x = 0;
    }
    x++;
  }
  out += to_string(x) + a;
  return out;
}

int main(){
  string input = "1113122113";

  for(int i = 0; i < 40; i++) input = next(input);

  cout << input.size() << endl;

  for(int i = 0; i < 10; i++) input = next(input);

  cout << input.size() << endl;

  return 0;
}
