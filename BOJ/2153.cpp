#include<iostream>
#include<cctype>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;
  int n=0, flag=1;
  for(int i=0;i<str.length();i++) {
    n+=((int)tolower(str[i]))-'a'+1;
  }
  for(int i=2;i<n;i++) {
    if(n%i==0) {
      flag=0;
      break;
    }
  }
  if(flag==1) cout << "It is a prime word." <<endl;
  else cout << "It is not a prime word." << endl;
  return 0;
}