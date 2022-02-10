#include<iostream>

using namespace std;

int main (){
  int T;
  cin >> T;
  int a=0, b=0, c=0, d;
  a = T/300;
  T = T%300;
  b = T/60;
  T = T%60;
  c = T/10;
  d = T%10;
  if(d) cout << -1 << endl;
  else cout << a << ' ' << b << ' ' << c << endl;
  return 0;
}