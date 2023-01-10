#include <iostream>
#include <queue>
using namespace std;

int N, M;
pair<int, int> ladder_or_snake[31];
bool visited[101] = {false};
int dist[101];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N + M; i++) {
    int a, b;
    cin >> a >> b;
    ladder_or_snake[i] = make_pair(a, b);
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;
  dist[1] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int i = 1; i <= 6; i++) {
      int next = curr + i;
      if (next > 100) continue;
      if (visited[next]) continue;
      dist[next] = dist[curr] + 1;
      visited[next] = true;

      for (int j = 0; j < N + M; j++) {
        if (next == ladder_or_snake[j].first) {
          // 여기서 이미 visited 한 곳 못 들어가게 하면 틀림
          // 뱀/사다리를 타는 경우,
          // 큐에 더 늦게 들어가는 경우가 기존 경로보다 더 짧은 경우 존재
          next = ladder_or_snake[j].second;
          // 처음 방문하는 경우 해당 값(거리) 그냥 넣어 줌
          if (dist[next] == 0) dist[next] = dist[curr] + 1;
          // 재방문하는 경우 현재 넣으려는 값(거리)이 더 작은 경우만 업데이트
          else if (dist[next] > dist[curr] + 1)
            dist[next] = dist[curr] + 1;
        }
      }
      visited[next] = true;

      q.push(next);
    }
  }
  cout << dist[100] << endl;

  return 0;
}