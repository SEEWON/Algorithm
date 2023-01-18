#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
  if(a.second!=b.second) return a.second < b.second;
  else return a.first < b.first;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i=0;i<N;i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end(), compare);

  for(int i=0;i<N;i++) {
    cout << v[i].first << ' ' << v[i].second << '\n';
  }

  return 0;
}