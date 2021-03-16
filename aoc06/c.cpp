#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct inst{
  pair<int,int> b;
  pair<int,int> e;
  int op = 0;
};

pair<int,int> pc (string in){
  pair<int,int> out;
  for(int i = 0; i < in.size(); i++) if(in[i] == ',') in[i] = ' ';
  stringstream s(in);
  s >> out.first >> out.second;
  return out;
}

inst parse(string in){
  inst out;
  stringstream s(in);
  string tmp;
  s >> tmp;
  if(tmp == "turn"){
    s >> tmp;
    out.op = (tmp == "on")?1:-1;
  }
  s >> tmp;
  out.b = pc(tmp);
  s >> tmp;
  s >> tmp;
  out.e = pc(tmp);
  return out;
}

int main(){
  bool lights[1000][1000];
  int lights2[1000][1000];
  
  string l;
  fstream f("input");

  for(int x = 0; x < 1000; x++){
    for(int y = 0; y < 1000; y++){
      lights[x][y] = false;
      lights2[x][y] = 0;
    }
  }

  while(getline(f,l)){
    inst i = parse(l);
    for(int x = i.b.first; x <= i.e.first; x++){
      for(int y = i.b.second; y <= i.e.second; y++){
	int a;
        if(i.op != 0){
          lights[x][y] = i.op > 0;
	  a = i.op;
        } else {
          lights[x][y] = !lights[x][y];
	  a = 2;
        }
	lights2[x][y] += a;
	if(lights2[x][y] < 0) lights2[x][y] = 0;
      }
    }
  }

  int tot = 0;
  int tot2 = 0;

  for(int x = 0; x < 1000; x++){
    for(int y = 0; y < 1000; y++){
      if(lights[x][y]) tot++;
      tot2 += lights2[x][y];
    }
  }

  cout << tot << endl;
  cout << tot2 << endl;

  return 0;
}
