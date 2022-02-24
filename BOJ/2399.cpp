#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long int * arr = new long int[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  long int ans=0;
  long int temp;
  for(int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      temp = arr[i]-arr[j];
      if(temp<0) temp=temp*(-1);
      ans+=temp;
    }
  }
  cout << ans*2 << endl;

  delete[] arr;
  return 0;
}