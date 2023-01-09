#include <iostream>
#include <queue>
using namespace std;

bool visited[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;
  char arr[N][M];
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < M; j++) {
      arr[i][j] = str.at(j);
    }
  }

  queue<pair<int, int>> q;
  int dist[N][M] = {0};

  q.push(make_pair(0, 0));
  visited[0][0] = true;
  dist[0][0] = 1;

  while (!q.empty()) {
    int curr_r = q.front().first;
    int curr_c = q.front().second;
    q.pop();

    int dir_r[4] = {0, 1, 0, -1};
    int dir_c[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
      int next_r = curr_r + dir_r[i];
      int next_c = curr_c + dir_c[i];
      if (next_r < 0 || next_r >= N) continue;
      if (next_c < 0 || next_c >= M) continue;
      if (visited[next_r][next_c]) continue;
      if (arr[next_r][next_c] == '0') continue;
      visited[next_r][next_c] = true;
      q.push(make_pair(next_r, next_c));
      dist[next_r][next_c] = dist[curr_r][curr_c] + 1;
    }
  }
  cout << dist[N - 1][M - 1] << endl;

  return 0;
}