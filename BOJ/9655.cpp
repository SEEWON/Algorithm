#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int res = N%4;

  if(res==1||res==3) cout << "SK" << endl;
  else cout << "CY" << endl;

  return 0;
}