#include<iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  double *price = new double[T];
  for(int i=0;i<T;i++) {
    cin >> price[i];
  }
  cout<<fixed; //소수점을 고정시켜서 표현하겠다
  cout.precision(2); //소수점 2자리까지 표현하겠다 .. fixed 안하고 하면 그냥 2자리만 표현하겠다는 뜻
  for(int i=0;i<T;i++) {
    cout << '$' << price[i]*0.8 <<endl;
  }

  return 0;
}