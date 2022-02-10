#include<iostream>

using namespace std;

int main() {
  int a1, a2, a3, a4;
  int b1, b2, b3, b4;
  int c1, c2, c3, c4;
  int res[3] = {0};

  cin >> a1 >> a2 >> a3 >> a4
      >> b1 >> b2 >> b3 >> b4
      >> c1 >> c2 >> c3 >> c4;

  res[0] = a1+a2+a3+a4;
  res[1] = b1+b2+b3+b4;
  res[2] = c1+c2+c3+c4;

  char ans;
  for(int i=0;i<3;i++) {
    if(res[i]==0) ans='D';
    else if(res[i]==1) ans='C';
    else if(res[i]==2) ans='B';
    else if(res[i]==3) ans='A';
    else ans='E';
    cout << ans << endl;
  }
  
  return 0;
}