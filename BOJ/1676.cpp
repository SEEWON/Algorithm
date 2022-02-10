#include<iostream>

using namespace std;

int main() {
  int n;
  int res=0;
  cin >> n;
  for(int i=0;i<n+1;i++) {
    int k=i;
    while(1) {
      if(k%5>0 || k==0) break;
      else {
        res++;
        k = k/5;
      }
    }
  }
  cout << res << endl;

  return 0;
}