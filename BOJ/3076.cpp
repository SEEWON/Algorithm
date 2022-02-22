#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int R, C, A, B;
  cin >> R >> C >> A >> B;

  for(int i=0;i<A*R;i++) {
    if ((i/A)%2==0) {
      //XX.. 순으로 뽑는 한 줄
      for(int k=0;k<C/2;k++) {
        for(int j=0;j<B;j++) {
          cout<<'X';
        }
        for(int j=0;j<B;j++) {
          cout<<'.';
        }
      }
      if(C%2==1) {
        for(int j=0;j<B;j++) {
          cout<<'X';
        }
      }
      cout << endl;
    }
    if ((i/A)%2==1) {
      //..XX 순으로 뽑는 한 줄
      for(int k=0;k<C/2;k++) {
        for(int j=0;j<B;j++) {
          cout<<'.';
        }
        for(int j=0;j<B;j++) {
          cout<<'X';
        }
      }
      if(C%2==1) {
        for(int j=0;j<B;j++) {
          cout<<'.';
        }
      }
      cout << endl;
    }
  }
  return 0;
}