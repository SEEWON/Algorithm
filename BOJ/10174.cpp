#include<iostream>
#include<cctype>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  cin.ignore();
  for(int j=0;j<T;j++){
    string str;
    getline(cin, str);
    int flag=1;
    for(int i=0;i<str.length()/2;i++) {
      if(toupper(str[i])!=toupper(str[str.length()-1-i])) {
        flag=0;
        break;
      }
    }
    if(flag==0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}