#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

int main() {
  string str;
  cin >> str;
  int check[26] = {0};

  for (int i=0; i<str.length(); i++) {
    str[i] = toupper(str[i]);
    check[str[i]-'A']++;
  }

  int idx=0;
  int dup=0;
  for(int i=0;i<26;i++) {
    if(check[i]>check[idx]) {
      idx = i;
    }
  }
  sort(check,check+26);
  if(check[24]==check[25]) {
    cout << '?' << endl;
    return 0;
  }
  
  char ans = idx+'A';
  cout << ans << endl;

  return 0;
}