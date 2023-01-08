#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long res_cut_wood(int h, vector<int>& v) {
  long long ans = 0;
  int curr = v.size() - 1;
  while (curr > -1) {
    int each_cut_wood = v[curr] - h;
    if (each_cut_wood <= 0) break;
    ans += each_cut_wood;
    curr--;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int left = 0;
  int right = v[n - 1];
  int h;

  while (left <= right) {
    int mid = (left + right) / 2;
    long long each_cut_wood = res_cut_wood(mid, v);
    if (each_cut_wood >= m) {
      left = mid + 1;
      h = mid;
    } else
      right = mid - 1;
  }
  cout << h << endl;
}