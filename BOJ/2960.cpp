#include<iostream>
#include<set>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  int flag=0;
  set <int> s;
  cin >> n >> k;
  for(int i=2;i<n+1;i++) {
    s.insert(i);
  }
  int i=1;
  int res=2;
  int multi=2;
  while(1) {
    if(i==k) {
      cout << res << endl;
      break;
    } else {
      i++;
      s.erase(res);
      for(auto it=s.begin();it!=s.end();it++) {
        if(*it % multi==0) {
          res = *it;
          flag = 1;
          break;
        }
      }
      if(flag!=1) {
        res=*s.begin();
        multi=*s.begin();
      }
      flag=0;
    }
  }
 
  return 0;
}