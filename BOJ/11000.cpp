#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  long long p, q;

  cin >> n;
  vector<pair<long long ,long long>> v;
  for(int i=0;i<n;i++) {
    cin >> p >> q;
    v.push_back(make_pair(p, q));
  }
  sort(v.begin(),v.end());

  priority_queue<long long, vector<long long>, greater<>> pq;
  pq.push(v[0].second);
  for(int i=1;i<n;i++) {
    pq.push(v[i].second);
    if(v[i].first>=pq.top()) pq.pop();
  }
  cout << pq.size() << endl;

  return 0;
}