#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, E;
int v1, v2;
long long dist[801];
vector<pair<int, int>> v[801];

void dijkstra(int start) {
  bool visited[801] = {0};
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[start] = 0;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    int curr_node = pq.top().second;
    int curr_cost = pq.top().first;
    pq.pop();

    if (visited[curr_node]) continue;
    visited[curr_node] = true;

    for (int i = 0; i < v[curr_node].size(); i++) {
      int next_node = v[curr_node][i].first;
      int next_cost = v[curr_node][i].second;
      if (dist[next_node] > curr_cost + next_cost) {
        dist[next_node] = curr_cost + next_cost;
        pq.push(make_pair(dist[next_node], next_node));
      }
    }
  }
}

// DIST 초기화
void init_dist() {
  for (int i = 1; i <= N; i++) {
    dist[i] = LLONG_MAX;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> E;

  //양방향 길 입력
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  cin >> v1 >> v2;

  //정답 경우의 수는 2가지.
  // start -> v1 -> v2 -> dest
  // start -> v2 -> v1 -> dest
  init_dist();
  dijkstra(1);
  long long start_to_v1 = dist[v1];
  long long start_to_v2 = dist[v2];
  init_dist();
  dijkstra(v1);
  long long v1_to_v2 = dist[v2];
  long long v1_to_dest = dist[N];
  init_dist();
  dijkstra(v2);
  long long v2_to_dest = dist[N];
  if ((start_to_v1 == LLONG_MAX || v1_to_v2 == LLONG_MAX ||
       v2_to_dest == LLONG_MAX) &&
      (start_to_v2 == LLONG_MAX || v1_to_v2 == LLONG_MAX ||
       v1_to_dest == LLONG_MAX))
    cout << -1 << endl;
  else
    cout << min(start_to_v1 + v1_to_v2 + v2_to_dest,
                start_to_v2 + v1_to_v2 + v1_to_dest)
         << endl;

  return 0;
}