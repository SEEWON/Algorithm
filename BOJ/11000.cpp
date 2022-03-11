#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, p, q;
  vector<pair<int,int>> v;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> p >> q;
    v.push_back(make_pair(q,p));
  }
  sort(v.begin(),v.end());

  int classCnt=0;
  int nowtime = v[0].first;
  v.erase(v.begin());
  while (v.size()!=0) {
    auto it = v.begin();
    while(it!=v.end()) {
      if((*it).second>=nowtime) {
        nowtime = (*it).first;
        v.erase(it);
      } else {
        it++;
      };
    }
    nowtime=0;
    classCnt++;
  }

  cout << classCnt << endl;
  return 0;
}