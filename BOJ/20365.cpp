#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  long long int n;
  cin >> n >> str;

  char color=str[0];
  long long int res=1;
  for(long long int i=1;i<n;i++) {
    if(str[i]!=color && str[i-1]==color) res++;
  }

  cout << res << endl;

  return 0;
}
