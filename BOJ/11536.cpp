#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;

  vector<string> str;
  vector<string> ascending;
  vector<string> descending;

  // string * str = new string[T];
  // string * ascending = new string[T];
  // string * descending = new string[T];
  string name;
  for(int i=0;i<T;i++) {
    cin >> name;
    str.push_back(name);
  }
  ascending = str;
  descending = str;

  sort(ascending.begin(), ascending.end());
  sort(descending.begin(), descending.end(), greater<>());
  
  if(str==ascending)
    cout << "INCREASING" << endl;
  else if(str==descending) cout << "DECREASING" << endl;
  else cout << "NEITHER" << endl;

  return 0;

}