#include<algorithm>
#include<iostream>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int * arr = new int[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr,arr+n);
  int res=0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<i+1;j++) {
      res+=arr[j];
    }
  }
  cout << res << endl;

  return 0;
}