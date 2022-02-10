#include<iostream>

using namespace std;

int main () {

  int coinCnt, money;
  cin >> coinCnt >> money;
  int * coins = new int[coinCnt];
  for (int i=0; i<coinCnt; i++) {
    cin >> coins[i];
  }

  int res=0;
  int i=coinCnt-1;
  while(money) {
    res+= money/coins[i];
    money = money%coins[i];
    i--;   
  }

  cout << res << endl;

  return 0;
}