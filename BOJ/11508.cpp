#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int * arr = new int[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr,arr+n,greater<int>());
  int res=0;
  for(int i=0;i<n;i++) {
    if(i%3==2) continue;
    res+=arr[i];
  }
  cout << res << endl;
}