#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  getline(cin, str);
  int minus=0;
  int res=0;
  int num=0;
  for(int i=0;i<str.length()+1;i++) {
    if(str[i]=='+'||str[i]=='-'||i==str.length()) {
      if(minus) {
        res-=num;
      } else {
        res+=num;
      }
      if(str[i]=='-') minus=1;
      num=0;
    } else {
      num= num*10+(str[i]-'0');
    }
  }
  cout << res << endl;
  return 0;
}