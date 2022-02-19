#include<iostream>

using namespace std;

class NumbersClass {
  public:
  int num1;
  int num2;
  int lcm; //최소공배수
  int gcd;  //최대공약수
};

NumbersClass GetLcm(NumbersClass element) {
  for(int i=1;;i++) {
    if((element.num1 * i) % element.num2 != 0) {
      continue;
    } else {
      element.lcm = element.num1 * i;
      break;
    }
  }
  return element;
}

NumbersClass GetGcd(NumbersClass element) {
  int smaller = element.num1;
  int bigger = element.num2;
  if(element.num2<element.num1) {
    smaller = element.num2;
    bigger = element.num1;
  }
  int biggest_div;
  for(int i=1;;i++) {
    if(smaller % i == 0 && bigger % i ==0) {
      biggest_div = i;
    }
    if(i>smaller) {
      break;
    }
  }
  element.gcd = biggest_div;
  return element;
}

int main() {
  int T;
  cin >> T;
  NumbersClass * arr = new NumbersClass[T];

  for(int i=0; i<T; i++){
    cin >> arr[i].num1 >> arr[i].num2;
    arr[i] = GetLcm(arr[i]);
    arr[i] = GetGcd(arr[i]);
  }

  for(int i=0; i<T; i++){
    cout << arr[i].lcm << ' ' << arr[i].gcd << endl;
  }

  delete[] arr;
  return 0;
}