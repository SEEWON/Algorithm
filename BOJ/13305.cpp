#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >>n;
  long long int * dis = new long long int[n-1];
  long long int * price = new long long int[n];
  long long int res=0;

  for(int i=0;i<n-1;i++) {
    cin >> dis[i];
  }
  for(int i=0;i<n;i++) {
    cin >> price[i];
  }
  long long int nowprice=price[0];
  for(int i=0;i<n-1;i++) {
    if(price[i]<nowprice) nowprice=price[i];
    res+=nowprice*dis[i];
  }
  cout << res << endl;
  return 0;
}