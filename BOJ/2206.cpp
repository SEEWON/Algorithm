#include <iostream>
#include <queue>
using namespace std;

short N, M;
bool arr[1001][1001];
bool visited[1001][1001];
// pair<좌표, 좌표>, pair<지금까지 얼마 왔는지, 벽 뚫었는지>
queue<pair<pair<short, short>, pair<short, bool>>> q;

short r_coor[4] = {0, 1, 0, -1};
short c_coor[4] = {1, 0, -1, 0};

int bfs() {
  q.push({{0, 0}, {1, true}});
  visited[0][0] = true;

  while (!q.empty()) {
    short curr_r = q.front().first.first;
    short curr_c = q.front().first.second;
    short curr_d = q.front().second.first;
    bool chance = q.front().second.second;
    if (curr_r == N - 1 && curr_c == M - 1) {
      cout << curr_d << endl;
      return 0;
    }
    q.pop();

    for (short i = 0; i < 4; i++) {
      short next_r = curr_r + r_coor[i];
      short next_c = curr_c + c_coor[i];
      if (next_r >= N || next_r < 0 || next_c >= M || next_c < 0) continue;
      if (arr[next_r][next_c] == 1 && chance == true) {
        q.push({{next_r, next_c}, {curr_d + 1, false}});
      }
      if (visited[next_r][next_c]) continue;
      if (arr[next_r][next_c] == 0 && chance == true) {
        q.push({{next_r, next_c}, {curr_d + 1, true}});
        visited[next_r][next_c] = true;
      } else if (arr[next_r][next_c] == 0 && chance == false) {
        q.push({{next_r, next_c}, {curr_d + 1, false}});
        visited[next_r][next_c] = true;
      }
    }
  }

  return 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (short i = 0; i < N; i++) {
    for (short j = 0; j < M; j++) {
      char in;
      cin >> in;
      arr[i][j] = in - '0';
    }
  }

  if (bfs()) cout << -1 << endl;

  return 0;
}