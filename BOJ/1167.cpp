#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V;
long long dist[100001];
vector<pair<int, int>> vec[100001];

void init_dist() {
  for (int i = 1; i <= V; i++) {
    dist[i] = LLONG_MAX;
  }
}

void dijkstra(int start) {
  bool visited[V + 1] = {0};
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  dist[start] = 0;
  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    int curr_node = pq.top().second;
    long long curr_cost = pq.top().first;
    pq.pop();

    if (visited[curr_node])
      continue;
    else
      visited[curr_node] = true;

    for (int i = 0; i < vec[curr_node].size(); i++) {
      int next_node = vec[curr_node][i].first;
      long long next_cost = vec[curr_node][i].second;
      if (dist[next_node] > curr_cost + next_cost) {
        dist[next_node] = curr_cost + next_cost;
        pq.push(make_pair(dist[next_node], next_node));
      }
    }
  }
}

long long find_max() {
  // 1에서 가장 먼 노드 찾기(2번 노드)
  //찾은 노드에서 다시 한번 가장 멀리 있는 노드(3번 노드) 찾기
  // 2번 노드 <-> 3번 노드가 트리에서 가장 멀리 떨어진 노드임!
  init_dist();
  dijkstra(1);
  int node_2;
  long long node_2_dist = 0;
  for (int i = 1; i <= V; i++) {
    if (node_2_dist < dist[i]) {
      node_2 = i;
      node_2_dist = dist[i];
    }
  }

  init_dist();
  dijkstra(node_2);
  int node_3;
  long long node_3_dist = 0;
  for (int i = 1; i <= V; i++) {
    if (node_3_dist < dist[i]) {
      node_3 = i;
      node_3_dist = dist[i];
    }
  }
  return node_3_dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> V;
  for (int i = 0; i < V; i++) {
    int curr_v, a, b;
    cin >> curr_v >> a;
    while (a != -1) {
      cin >> b;
      vec[curr_v].push_back(make_pair(a, b));
      cin >> a;
    }
  }
  cout << find_max() << endl;
  return 0;
}