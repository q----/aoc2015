#include <iostream>
#include <vector>

using namespace std;

unsigned long long int next(unsigned long long int x){
  x *= 252533;
  return x % 33554393;
}

int tri(int in){
  return (in * (in + 1))/2;
}

int seq(vector<int> in){
  return tri(in[0] + in[1] - 2) + in[1];
}
  

int main(){
  unsigned long long int a = 20151125;

  vector<int> goal = {2978,3083};
  
  int g = seq(goal);

  for(int x = 1; x < g; x++){
    a = next(a);
  }

  cout << a << endl;
  return 0;

}
