#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
  vector <int> v;
  vector <int> ans;
  int T,n;
  string str;
  cin >> T;
  for(int i=0;i<T;i++) {
    cin >> str;
    if(str=="push_front") {
      cin >> n;
      v.insert(v.begin(),n);
    } else if(str=="push_back") {
      cin >> n;
      v.push_back(n);
    } else if(str=="pop_front") {
      if(v.size()==0) ans.push_back(-1);
      else {
        ans.push_back(v.front());
        v.erase(v.begin());
      }
    } else if(str=="pop_back") {
      if(v.size()==0) ans.push_back(-1);
      else {
        ans.push_back(v.back());
        v.pop_back();
      }
    } else if(str=="size") {
      ans.push_back(v.size());
    } else if(str=="empty") {
      if(v.size()==0) ans.push_back(1);
      else ans.push_back(0);
    } else if(str=="front") {
      if(v.size()==0) ans.push_back(-1);
      else {
        ans.push_back(v.front());
      }
    } else if(str=="back") {
      if(v.size()==0) ans.push_back(-1);
      else {
        ans.push_back(v.back());
      }
    }
  }

  for(int i=0;i<ans.size();i++) {
    cout << ans[i] << endl;
  }

  return 0;
}