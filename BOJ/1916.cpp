#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
int start, dest;
int dist[1001];
bool visited[1001] = {0};

void dijkstra(int start) {
  // <현재 노드까지 오는 데 걸린 최소 cost, 현재 노드>로 구성된 우선순위 큐
  // 늘 최소 cost인 경우에 대해 다음 노드를 탐색하기 위해 우선순위 큐 사용!
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push(make_pair(0, start));
  dist[start] = 0;
  while (!pq.empty()) {
    int curr_cost = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();
    if (visited[curr_node]) continue;
    visited[curr_node] = true;
    for (int i = 0; i < v[curr_node].size(); i++) {
      int next_cost = v[curr_node][i].second;
      int next_node = v[curr_node][i].first;
      if (curr_cost + next_cost < dist[next_node]) {
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
  return 0;
}