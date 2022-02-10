#include<iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int *price = new int[n];

  for(int i=0; i<n; i++) {
    int res;
    cin >> res;
    int m;
    cin >> m;
    for (int j=0;j<m;j++) {
      int optionCnt, optionPrice;
      cin >> optionCnt >> optionPrice;
      res += optionCnt * optionPrice;
    }
    price[i] = res;
  }

  for(int i=0; i<n; i++) {
    cout << price[i] << endl;
  }
  delete[] price;
  return 0;
}