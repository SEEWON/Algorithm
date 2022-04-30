#include<iostream>

using namespace std;

int R, C, N;
char arr[201][201]={0};
char arr1[201][201]={0};  //N%4가 1일 때 arr
char arr3[201][201]={0};  //N%4가 3일 때 arr

void boom3() {
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      if(arr[i][j]=='O') {
        arr3[i][j]='O';
        if(i-1>=0) arr3[i-1][j]='O';
        if(i+1<R) arr3[i+1][j]='O';
        if(j-1>=0) arr3[i][j-1]='O';
        if(j+1<C) arr3[i][j+1]='O';
      }
    }
  }
}
void boom1() {
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      if(arr3[i][j]!='O') {
        arr1[i][j]='.';
        if(i-1>=0) arr1[i-1][j]='.';
        if(i+1<R) arr1[i+1][j]='.';
        if(j-1>=0) arr1[i][j-1]='.';
        if(j+1<C) arr1[i][j+1]='.';
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> R >> C >> N;

  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      cin >> arr[i][j];
    }
  }

  boom3();
  boom1();

  if(N==1) {
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
        cout << arr[i][j];
      }
      cout << '\n';
    }
  } else if (N%4==1) {
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
        if(arr1[i][j]=='.') cout << '.';
        else cout << 'O';
      }
      cout << '\n';
    }
  } else if (N%2==0) {
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
        cout << 'O';
      }
      cout << '\n';
    }
  } else {
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
        if(arr3[i][j]=='O') cout << '.';
        else cout << 'O';
      }
      cout << '\n';
    }
  }

  return 0;
}