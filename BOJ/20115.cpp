#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  double * drink = new double[n];
  for(int i=0;i<n;i++) {
    cin >> drink[i];
  }

  sort(drink, drink+n);
  double ans=drink[n-1];
  for(int i=0;i<n-1;i++) {
    ans+=drink[i]/2;
  }

  cout << ans << endl;

  return 0;
}