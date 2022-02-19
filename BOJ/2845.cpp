#include<iostream>

using namespace std;

int main (){

  int people, area;
  cin >> people >> area;
  int num = people*area;
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << a-num << ' ' << b-num << ' ' << c-num << ' ' << d-num << ' ' << e-num << endl;
  return 0;
}