#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<int> s;
  vector<pair<int, int>> v;  // 수, 순서
  int t1, t2;
  cin >> t1;
  for (int i = 0; i < t1; i++) {
    int n;
    cin >> n;
    s.insert(n);
  }
  cin >> t2;
  for (int i = 0; i < t2; i++) {
    int n;
    cin >> n;
    v.push_back(make_pair(n, i));
  }

  sort(v.begin(), v.end());
  int ans[t2];

  auto it = s.begin();
  for (int i = 0; i < t2; i++) {
    if (*it == v[i].first) {
      ans[v[i].second] = 1;
    } else if (*it > v[i].first) {
      ans[v[i].second] = 0;
      continue;
    } else if (*it < v[i].first) {
      // 더 이상 *it가 v[i]보다 작지 않아질 때까지
      while (*it < v[i].first && it != s.end()) {
        it++;
      }
      if (*it == v[i].first)
        ans[v[i].second] = 1;
      else
        ans[v[i].second] = 0;
    }
  }

  for (int i = 0; i < t2; i++) {
    cout << ans[i] << '\n';
  }
}
