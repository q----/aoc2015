#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct box{
  int x;
  int y;
  int z;
};

int volume(box x){
  return x.x * x.y * x.z;
}

int rib(box x){
  int out = volume(x);
  int max = (x.x > x.y)? x.x: x.y;
  max = (max > x.z)? max: x.z;
  out += 2 * (x.x + x.y + x.z - max);
  return out;
}

int sa(box x){
  int a = x.x * x.y;
  int b = x.x * x.z;
  int c = x.y * x.z;
  int min = (a < b)?a:b;
  min = (min < c)?min:c;
  return 2 * (a+b+c) + min;
}

int main(){
  string line;
  ifstream input ("input");
  int paper = 0;
  int ribbon = 0;

  while(getline(input,line)){
    for(int i = 0; i < line.size(); i++) if(line[i] == 'x') line[i] = ' ';
    stringstream s(line);
    box p;
    s >> p.x >> p.y >> p.z;;
    paper += sa(p);
    ribbon += rib(p);
  }

  cout << paper << endl;
  cout << ribbon << endl;

  return 0;
}
