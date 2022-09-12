#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<pair<int, int>> v[1001];
int dist[1001];
int N, M, X;

void init_dist() {
  for (int i = 1; i <= N; i++) {
    dist[i] = INT_MAX;
  }
}

void dijkstra(int start) {
  int visited[1001] = {0};
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    int curr_cost = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();

    if (visited[curr_node]) continue;
    visited[curr_node] = true;

    for (int i = 0; i < v[curr_node].size(); i++) {
      int next_cost = v[curr_node][i].second;
      int next_node = v[curr_node][i].first;
      if (dist[next_node] > curr_cost + next_cost) {
        dist[next_node] = curr_cost + next_cost;
        pq.push(make_pair(dist[next_node], next_node));
      }
    }
  }
}

//왕복하는 데 소요되는 시간 계산
int calculate_round_trip(int num) {
  init_dist();
  dijkstra(num);
  int go = dist[X];
  init_dist();
  dijkstra(X);
  int come_back = dist[num];
  return go + come_back;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> X;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i == X) continue;
    ans = max(calculate_round_trip(i), ans);
  }

  cout << ans << endl;
  return 0;
}