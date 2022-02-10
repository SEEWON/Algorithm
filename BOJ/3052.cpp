#include<iostream>
#include<algorithm>

using namespace std;

int main () {
  int numbers[10];
  int remainders[10];

  for(int i=0; i<10; i++) {
    cin >> numbers[i];
    remainders[i] = numbers[i] % 42;
  }

  sort(remainders, remainders+10);

  int res=10;
  for (int i=0;i<9;i++) {
    if(remainders[i]==remainders[i+1]) {
      res--;
    }
  }
  cout << res << endl;

  return 0;
}