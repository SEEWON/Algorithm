#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector <string> v;
  string name, state;
  int T;
  cin >> T;
  for(int i=0;i<T;i++) {
    cin >> name >> state;
    if(state=="enter") v.push_back(name);
    else {
      for(int j=0;j<v.size();j++) {
        if(v[j]==name) {
          v.erase(v.begin()+j);
          break;
          }
      }
    }
  }
  for(int i=0;i<v.size();i++) {
    sort(v.rbegin(),v.rend());
  }
  for(int i=0;i<v.size();i++) {
    cout << v[i] << '\n';
  }
  return 0;
}