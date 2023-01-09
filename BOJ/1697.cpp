#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001];
int time[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  queue<int> q;
  q.push(N);
  visited[N] = true;
  time[N] = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    bool flag = 0;
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        int next = curr - 1;
        if (next < 0) continue;
        if (visited[next]) continue;
        q.push(next);
        visited[next] = true;
        time[next] = time[curr] + 1;
        if (next == K) {
          flag = 1;
          break;
        }
      } else if (i == 1) {
        int next = curr + 1;
        if (next > 100000) continue;
        if (visited[next]) continue;
        q.push(next);
        visited[next] = true;
        time[next] = time[curr] + 1;
        if (next == K) {
          flag = 1;
          break;
        }
      } else {
        int next = curr * 2;
        if (next < 0 || next > 100000) continue;
        if (visited[next]) continue;
        q.push(next);
        visited[next] = true;
        time[next] = time[curr] + 1;
        if (next == K) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) break;
  }
  cout << time[K] << endl;

  return 0;
}