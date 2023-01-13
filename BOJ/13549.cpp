#include <climits>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[100001];
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;

  for (int i = 0; i < 100001; i++) dist[i] = INT_MAX;
  q.push(N);
  dist[N] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == K) {
      cout << dist[K] << endl;
      return 0;
    }
    for (int i = 0; i < 3; i++) {
      // curr*2 이동
      if (i == 0) {
        int next = curr * 2;
        if (next >= 0 && next <= 100000) {
          if (dist[next] > dist[curr]) {
            q.push(next);
            dist[next] = dist[curr];
          }
        }
      }

      // curr+1 이동
      else if (i == 1) {
        int next = curr + 1;
        if (next <= 100000) {
          if (dist[next] > dist[curr] + 1) {
            q.push(next);
            dist[next] = dist[curr] + 1;
          }
        }
      }

      // curr-1 이동
      else {
        int next = curr - 1;
        if (next >= 0) {
          if (dist[next] > dist[curr] + 1) {
            q.push(next);
            dist[next] = dist[curr] + 1;
          }
        }
      }
    }
  }

  return 0;
}