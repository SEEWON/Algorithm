#include <iostream>
#include <queue>

using namespace std;

int ans[50];
int field[50][50];
int visited[50][50];
queue<pair<int, int>> q;
queue<pair<int, int>> qq;
int M, N, K;

int nextXOffset[4] = {1, 0, -1, 0};
int nextYOffset[4] = {0, 1, 0, -1};

void resetField() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      field[i][j] = 0;
      visited[i][j] = 0;
    }
  }
}

// 큐 안의 큐로, 카운트 하나 늘어난 건에 대해 진행 가능한만큼 BFS진행.
void bfsInBfs() {
  while (!qq.empty()) {
    int currX = qq.front().first;
    int currY = qq.front().second;
    qq.pop();
    field[currX][currY] = 0;

    for (int i = 0; i < 4; i++) {
      int nextX = currX + nextXOffset[i];
      int nextY = currY + nextYOffset[i];
      if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) continue;
      if (visited[nextX][nextY] == 1 || field[nextX][nextY] == 0) continue;
      qq.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = 1;
    }
  }
}

void solve(int t) {
  int cnt = 0;

  while (!q.empty()) {
    int currX = q.front().first;
    int currY = q.front().second;
    q.pop();
    if (field[currX][currY] == 1)
      cnt++;
    else
      continue;  //지금 필드가 0이라면 이미 bfsInbfs에서 처리했을것
    field[currX][currY] = 0;

    for (int i = 0; i < 4; i++) {
      int nextX = currX + nextXOffset[i];
      int nextY = currY + nextYOffset[i];
      if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) continue;
      if (visited[nextX][nextY] == 1 || field[nextX][nextY] == 0) continue;
      qq.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = 1;
    }
    bfsInBfs();
  }

  ans[t] = cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    resetField();
    cin >> M >> N >> K;
    int x, y;
    for (int j = 0; j < K; j++) {
      cin >> x >> y;
      field[x][y] = 1;
      q.push(make_pair(x, y));
    }
    solve(i);
  }

  for (int i = 0; i < T; i++) cout << ans[i] << endl;
  return 0;
}