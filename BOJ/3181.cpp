#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main (void){
  string ignore[10]= {" i ", " pa ", " te ", " ni ", " niti ", " a ", " ali ", " nego ", " no ", " ili "};
  string str;
  vector <char> v;
  getline (cin, str);
  for(int i=0;i<10;i++) {
    auto res = str.find(ignore[i]);
    if(res!=string::npos && res>0 ) {
      str.replace(res,ignore[i].length()," ");
    }
  }
  v.push_back(str[0]);
  for(int i=1;i<str.length()-1;i++) {
    if(str[i]==' ') {
      v.push_back(str[i+1]);
    }
  }

  for(int i=0;i<v.size();i++) {
    cout << (char)toupper(v[i]);
  }
  return 0;
}