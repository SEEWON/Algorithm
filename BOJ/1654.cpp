#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long cal_max_cnt(int length, vector<int>& v) {
  long long rtn = 0;
  for (int i = 0; i < v.size(); i++) {
    rtn += (v[i] / length);
  }
  return rtn;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int K, N;
  cin >> K >> N;

  vector<int> v(K);
  for (int i = 0; i < K; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  long long left = 1;
  long long right = v[K - 1];
  long long max = 0;

  while (left <= right) {
    long long mid = (left + right) / 2;
    long long each_cnt = cal_max_cnt(mid, v);

    if (each_cnt < N) {
      right = mid - 1;
    } else {
      left = mid + 1;
      max = mid;
    }
  }

  cout << max << endl;
}