#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long int a, b;
  cin >> a >> b;
  int ans=0;
  while(1) {
    if(a==b) break;
    else if(a>b) {
      ans = -2;
      break;
    }
    if(b%10==1) {
      b=b/10;
      ans++;
      continue;
    }
    else if(b%2==0) {
      b=b/2;
      ans++;
      continue;
    }
    else {
      ans=-2;
      break;
    }
  }

  cout << ans+1 << endl;

  return 0;
}