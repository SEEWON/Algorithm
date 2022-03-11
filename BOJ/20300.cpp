#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<long long int> v;
  cin >> n;
  long long int * arr = new long long int[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  if(n%2==1) {
    v.push_back(arr[n-1]);
    for(int i=0;i<n/2;i++) {
      v.push_back(arr[i]+arr[n-i-2]);
    }
  } else {
    for(int i=0;i<n/2;i++) {
      v.push_back(arr[i]+arr[n-i-1]);
    }
  }
  sort(v.begin(),v.end(),greater<>());
  cout << v[0] << endl;
  return 0;
}