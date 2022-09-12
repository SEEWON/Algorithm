#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<pair<int, int>> v[20001];
int V, K;
long long E;
long long dist[20001];

void dijkstra(int start) {
  bool visited[20001] = {0};
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    long long curr_cost = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();

    if (visited[curr_node]) continue;
    visited[curr_node] = true;

    for (int i = 0; i < v[curr_node].size(); i++) {
      long long next_cost = v[curr_node][i].second;
      int next_node = v[curr_node][i].first;
      if (dist[next_node] > curr_cost + next_cost) {
        dist[next_node] = curr_cost + next_cost;
        pq.push(make_pair(dist[next_node], next_node));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> V >> E >> K;
  for (long long i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }

  for (int i = 1; i <= V; i++) {
    dist[i] = LLONG_MAX;
  }
  dijkstra(K);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == LLONG_MAX)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }

  return 0;
}