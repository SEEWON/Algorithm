#include <iostream>
#include <queue>

using namespace std;

int width, height;
int arr[1001][1001] = {0};
bool visited[1001][1001];
queue<pair<int, int>> q;
int R_cor[4] = {0, 1, 0, -1};
int C_cor[4] = {1, 0, -1, 0};
int ans = 0;
pair<int, int> pivot = make_pair(-1, -1);

void bfs() {
  int oneLoopDone = 0;
  while (!q.empty()) {
    int currR = q.front().first;
    int currC = q.front().second;
    q.pop();
    if (pivot.first == currR && pivot.second == currC) oneLoopDone = 1;

    for (int i = 0; i < 4; i++) {
      int nextR = currR + R_cor[i];
      int nextC = currC + C_cor[i];
      if (visited[nextR][nextC] || nextR >= height || nextR < 0 ||
          nextC >= width || nextC < 0)
        continue;
      //하루가 지났고 다음 토마토를 큐에 넣을 때마다!
      if (oneLoopDone) {
        ans++;
        oneLoopDone = 0;
        pivot = make_pair(nextR, nextC);
      }
      visited[nextR][nextC] = true;
      q.push(make_pair(nextR, nextC));
    }
  }
}

int checkIsolated() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (visited[i][j] == false) return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> width >> height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int input;
      cin >> input;
      arr[i][j] = input;
      if (input == 1) {
        q.push(make_pair(i, j));
        if (pivot.first == -1) pivot = make_pair(i, j);
      }
      if (input != 0) visited[i][j] = true;  //익었거나 비어있으면 사전 방문처리
    }
  }

  bfs();

  if (checkIsolated())
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}