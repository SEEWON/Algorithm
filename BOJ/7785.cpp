#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map <string, int, greater<>> m;
  string name, state;
  int T;
  cin >> T;
  for(int i=0;i<T;i++) {
    cin >> name >> state;
    if(state=="enter") m[name]=1;
    else {
      m[name]=0;
    }
  }
  for(auto i=m.begin(); i!=m.end(); i++) {
    if(i->second==1)
    cout << i->first << '\n';
  }
  return 0;
}