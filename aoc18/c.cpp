#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<bool> parse(string l){
  vector<bool> out;
  for(char c : l) out.push_back(c == '#');
  return out;
}

vector<vector<bool>> next(vector<vector<bool>> in, bool two = false){
  vector<vector<bool>> out;
  for(int i = 0; i < 100; i++){
    vector<bool> line;
    for(int j = 0; j < 100; j++){
      int adj = 0;
      if(i-1 >= 0 && j - 1 >= 0 && in[i-1][j-1]) adj++;
      if(j - 1 >= 0 && in[i][j-1]) adj++;
      if(i+1 <= 99 && j - 1 >= 0 && in[i+1][j-1]) adj++;
      if(i-1 >= 0 && in[i-1][j]) adj++;
      if(i+1 <= 99 && in[i+1][j]) adj++;
      if(i-1 >= 0 && j + 1 <= 99 && in[i-1][j+1]) adj++;
      if(j + 1 <= 99 && in[i][j+1]) adj++;
      if(i+1 <= 99 && j + 1 <= 99 && in[i+1][j+1]) adj++;
      if(in[i][j]){
	line.push_back(adj == 2 || adj == 3);
      } else {
        line.push_back(adj == 3);
      }
    }
    out.push_back(line);
  }
  if(two){
    out[0][0] = true;
    out[0][99] = true;
    out[99][0] = true;
    out[99][99] = true;
  }
  return out;
}

int count(vector<vector<bool>> in){
  int out = 0;
  for(auto a : in) for(bool b : a) if(b) out++;
  return out;
}

int main(){
  ifstream f("input");
  string l;

  vector<vector<bool>> lights;
  vector<vector<bool>> lights2;

  while(getline(f,l)){
    vector<bool> curr = parse(l);
    lights.push_back(curr);
    lights2.push_back(curr);
  }

  for(int i = 0; i < 100; i++){
    lights = next(lights);
    lights2 = next(lights2, true);
  }

  cout << count(lights) << endl;
  cout << count(lights2) << endl;

  return 0;
}

