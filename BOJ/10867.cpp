#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  int *arr = new int[T];
  for(int i=0;i<T;i++) {
    cin>>arr[i];
  }

  sort(arr,arr+T);

  cout << arr[0];
  for(int i=1;i<T;i++) {
    if(arr[i]==arr[i-1]) continue;
    cout << ' ' << arr[i];
  }

  cout << endl;
  return 0;
}