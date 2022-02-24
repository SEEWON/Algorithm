#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  long int m;
  long int sum=0;
  long int temp;
  cin>>n>>m;
  int * arr = new int[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      for(int k=j+1;k<n;k++) {
        temp = arr[i]+arr[j]+arr[k];
        if(m>=temp && m-temp<m-sum) sum=temp;
      }
    }
  }
  cout << sum << endl;

  delete[] arr;
  return 0;
}
