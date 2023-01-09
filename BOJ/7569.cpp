#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
short arr[101][101][101];  // arr[i][j][k]는 i층의 j행 k열
bool visited[101][101][101];
int dist[101][101][101];

short dir_h[6] = {0, 0, 0, 0, 1, -1};
short dir_r[6] = {1, 0, -1, 0, 0, 0};
short dir_c[6] = {0, 1, 0, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  queue<pair<int, pair<int, int>>> q;  // <높이, <행, 열>>
  cin >> M >> N >> H;
  // 5 3 2

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        int in;
        cin >> in;
        arr[i][j][k] = in;
        if (in == 1) {
          q.push(make_pair(i, make_pair(j, k)));
          visited[i][j][k] = true;
          dist[i][j][k] = 0;
        }
      }
    }
  }

  while (!q.empty()) {
    int curr_h = q.front().first;
    int curr_r = q.front().second.first;
    int curr_c = q.front().second.second;

    q.pop();
    for (int i = 0; i < 6; i++) {
      int next_h = curr_h + dir_h[i];
      int next_r = curr_r + dir_r[i];
      int next_c = curr_c + dir_c[i];

      if (next_h < 0 || next_h >= H) continue;
      if (next_r < 0 || next_r >= N) continue;
      if (next_c < 0 || next_c >= M) continue;
      if (visited[next_h][next_r][next_c]) continue;
      if (arr[next_h][next_r][next_c] == -1) continue;
      visited[next_h][next_r][next_c] = true;
      q.push(make_pair(next_h, make_pair(next_r, next_c)));
      dist[next_h][next_r][next_c] = dist[curr_h][curr_r][curr_c] + 1;
    }
  }

  int max = 0;
  bool impossible = false;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (dist[i][j][k] > max) max = dist[i][j][k];
        if (!visited[i][j][k] && arr[i][j][k] == 0) impossible = true;
      }
    }
  }
  if (impossible)
    cout << -1 << endl;
  else
    cout << max << endl;
  return 0;
}