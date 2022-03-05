#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<pair<int, int>> v;
  int n;
  int p,q;
  int res=1;
  int nowtime=0;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> p >> q;
    v.push_back(make_pair(q,p));
  }
  sort(v.begin(),v.end());
  //현재 시각은 첫 번째 회의가 끝난 시간
  nowtime =v[0].first;
  for(int i=1;i<v.size();i++) {
    if(v[i].second>=nowtime) {
      nowtime = v[i].first;
      res++;
    }
  }
  cout << res << endl;

  return 0;
}