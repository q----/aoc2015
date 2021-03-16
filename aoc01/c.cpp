#include <iostream>
#include <fstream>

using namespace std;

int main(){
  int floor = 0;
  int basement = 10000;
  string line;
  ifstream input ("input");

  while(getline(input,line)){
    for(int i = 0; i < line.size(); i++){
      floor += (line[i] == '(')?1:-1;
      if(floor == -1 && basement > i){
        basement = i;
      }
    }
  }

  cout << floor << endl;
  cout << basement + 1 << endl;

  return 0;
}
