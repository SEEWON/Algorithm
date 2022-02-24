#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  if(N<100) {
    cout << N <<endl;
  } else {
    int res=99;
    int a, b, c;
    for(int i=100;i<N+1;i++) {
      a = i/100;
      b = (i%100)/10;
      c = i%10;
      if(b-a==c-b) res++;
    }
    cout << res << endl;
  }

  return 0;
}