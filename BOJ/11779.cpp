#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
int tracking[1001];
vector<int> ans;
int start, dest;
int dist[1001];
bool visited[1001] = {0};

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push(make_pair(0, start));
  dist[start] = 0;
  while (!pq.empty()) {
    int curr_cost = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();

    if (curr_node == dest) return;

    if (visited[curr_node]) continue;
    visited[curr_node] = true;

    for (int i = 0; i < v[curr_node].size(); i++) {
      int next_cost = v[curr_node][i].second;
      int next_node = v[curr_node][i].first;
      if (curr_cost + next_cost < dist[next_node]) {
        tracking[next_node] = curr_node;
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

  cin >> N >> M;

  // dist 초기화
  for (int i = 1; i <= N; i++) {
    dist[i] = INT_MAX;
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }
  cin >> start >> dest;
  dijkstra(start);
  cout << dist[dest] << endl;

  int temp = dest;
  while (temp != 0) {
    ans.push_back(temp);
    temp = tracking[temp];
  }
  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';

  return 0;
}