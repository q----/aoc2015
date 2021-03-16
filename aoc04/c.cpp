#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

string md5sum(string in){
  unsigned char result[MD5_DIGEST_LENGTH];
  MD5((unsigned char*)in.c_str(), in.size(), result);
  ostringstream oss;
  for(int i = 0; i < MD5_DIGEST_LENGTH; ++i){
    oss << hex << setw(2) << setfill('0') << +result[i];
  }
  return oss.str();
}

int main(){
  string input = "bgvyzdsv";
  int num = 0;
  string m;

  do{
    m = md5sum(input + to_string(++num));
  }while(m.substr(0,5) != "00000");
    
  cout << num << endl;

  num--;

  do{
    m = md5sum(input + to_string(++num));
  }while(m.substr(0,6) != "000000");

  cout << num << endl;

  return 0;
} 
