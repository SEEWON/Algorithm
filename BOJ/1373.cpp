#include<iostream>
#include<string>
using namespace std;

int main(void) {
  string num2;
  cin >> num2;
  int digit = num2.length();
  int i=0;
  if(digit%3==2) {
    cout<< (num2[0]-'0')*2+(num2[1]-'0') ;
    i=2;
  } else if(digit%3==1) {
    cout << num2[0];
    i=1;
  }
  for(;i<digit-2;i+=3) {
    cout<< (num2[i]-'0')*4+(num2[i+1]-'0')*2+(num2[i+2]-'0');
  }
  cout << endl;
  return 0;
}