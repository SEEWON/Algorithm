#include<iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i=0;i<n;i++) {
    int res;
    string str;
    cin >> res >> str;
    for(int j=0;j<str.length();j++) {
      if(str[j]=='b') res--;
      else res++;
    }
    cout << "Data Set " << i+1 << ":\n" << res << endl;
  }

  return 0;
}