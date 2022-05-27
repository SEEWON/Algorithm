#include <iostream>

using namespace std;

int asset, asset_J, asset_S;
int stock_price[14];

void Joonhyeon() {
  asset_J = asset;
  int stock_J = 0;
  for (int i = 0; i < 14; i++) {
    if (asset_J >= stock_price[i]) {
      int buy_cnt = asset_J / stock_price[i];
      stock_J += buy_cnt;
      asset_J -= buy_cnt * stock_price[i];
    }
  }
  asset_J = stock_J * stock_price[13] + asset_J;
}

void Sungmin() {
  asset_S = asset;
  int stock_S = 0;
  for (int i = 3; i < 13; i++) {
    if (stock_price[i - 3] < stock_price[i - 2] &&
        stock_price[i - 2] < stock_price[i - 1] &&
        stock_price[i - 1] < stock_price[i]) {
      //전량 매도
      asset_S += stock_S * stock_price[i];
      stock_S = 0;
    }
    if (stock_price[i - 3] > stock_price[i - 2] &&
        stock_price[i - 2] > stock_price[i - 1] &&
        stock_price[i - 1] > stock_price[i]) {
      //전량 매수
      int buyCnt = asset_S / stock_price[i];
      stock_S += buyCnt;
      asset_S -= buyCnt * stock_price[i];
    }
  }
  asset_S = stock_S * stock_price[13] + asset_S;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> asset;
  for (int i = 0; i < 14; i++) {
    cin >> stock_price[i];
  }

  Joonhyeon();
  Sungmin();

  if (asset_J > asset_S)
    cout << "BNP";
  else if (asset_J < asset_S)
    cout << "TIMING";
  else
    cout << "SAMESAME";
  cout << endl;

  return 0;
}