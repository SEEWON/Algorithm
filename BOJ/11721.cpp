#include<iostream>
#include<string>

using namespace std;

int main() {
  string str;
  cin >> str;

  int k=0;
  int isDividedByTen = str.length()%10 ? str.length()/10+1 : str.length()/10 ;
  for (int i=0; i<isDividedByTen; i++) {
    cout << str.substr(k,10) << endl;
    k= k+10;
  }

  return 0;
}