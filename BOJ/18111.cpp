#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, B;
  int max_h = -1, min_h = INT_MAX;

  cin >> N >> M >> B;
  vector<int> v(N * M);
  for (int i = 0; i < N * M; i++) {
    int in;
    cin >> in;
    v[i] = in;
    if (in > max_h) max_h = in;
    if (in < min_h) min_h = in;
  }

  sort(v.begin(), v.end());
  int min_time = INT_MAX;
  int min_time_h = -1;
  // i는 각 회차에서 맞추기로 한 높이
  for (int i = min_h; i <= max_h; i++) {
    int time = 0;
    int block = B;
    int flag = 0;
    for (int j = N * M - 1; j > -1; j--) {
      if (i == v[j]) continue;
      // 블록을 깎아야 하는 경우
      else if (i < v[j]) {
        int cut_block = v[j] - i;
        time += cut_block * 2;
        block += cut_block;
      }
      // 블록을 놓아야 하는 경우
      else {
        int put_block = i - v[j];
        time += put_block;
        block -= put_block;
        if (block < 0) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 1) continue;
    if (time <= min_time) {
      min_time = time;
      min_time_h = max(min_time_h, i);
    }
  }
  cout << min_time << ' ' << min_time_h << endl;
}
