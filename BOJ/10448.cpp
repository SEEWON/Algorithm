#include<iostream>
using namespace std;

int main (void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T[44];
  T[0]=1;
  for(int i=1;i<44;i++) {
    T[i] = (2+i)*(1+i)/2;
  }
  int n;
  cin >> n;
  for(int s=0;s<n;s++) {
    int p;
    int res=0;
    cin >> p;
    for(int i=0;i<44;i++) {
      for(int j=0;j<44;j++) {
        for(int k=0;k<44;k++) {
          if(p==T[i]+T[j]+T[k]) res=1;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}