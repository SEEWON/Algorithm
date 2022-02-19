#include<iostream>
#include<string>

using namespace std;

int main (){
  string str;
  int happy=0, sad=0;
  getline(cin, str);
  for(int i=0;i<str.length()-2;i++) {
    if(str.substr(i,3)==":-)") happy++;
    if(str.substr(i,3)==":-(") sad++;
  }
  if (happy==0 && sad==0) cout << "none" << endl;
  else if(happy>sad) cout << "happy" << endl;
  else if(happy<sad) cout << "sad" << endl;
  else if (happy==sad) cout << "unsure" << endl;
  return 0;
}