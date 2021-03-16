#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> aaa (string l){
  for(int i = 0; i < l.size(); i++){
    if(l[i] == ',') l[i] = ' ';
  }
  vector<int> out;
  stringstream s(l);
  int a,b,c,d,e;
  string t;
  s >> t >> t >> a >> t >> b >> t >> c >> t >> d >> t >> e;
  out.push_back(a);
  out.push_back(b);
  out.push_back(c);
  out.push_back(d);
  out.push_back(e);
  return out;
}

int main(){
  ifstream f ("input");
  string l;
  vector<vector<int>> woo;
  while(getline(f,l)) woo.push_back(aaa(l));

  int max = 0;
  int max2 = 0;

  for(int x = 0; x <= 100; x++){
    for(int y = 0; y <= 100-x; y++){
      for(int z = 0; z <= 100-x-y; z++){
	int tmp = 1;
	for(int w = 0; w < 4; w++){
	  int temp = x * woo[0][w] + y * woo[1][w] + z * woo[2][w] + (100-x-y-z) * woo[3][w];
	  temp = (temp > 0)? temp: 0;
          tmp *= temp;
	}
        max = (max > tmp)? max:tmp;
	if(x * woo[0][4] + y * woo[1][4] + z * woo[2][4] + (100-x-y-z) * woo[3][4] == 500){
          max2 = (max2 > tmp)? max2:tmp;
	}
      }
    }
  }

  cout << max << endl;
  cout << max2 << endl;

  return 0;
}
