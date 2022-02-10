#include<iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  char *arr = new char[n];
  cin >> arr;
  
  int res=0;
  for(int i=0; i<n; i++) {
    res += arr[i]-'0';
  }
    cout << res;

  return 0;
}