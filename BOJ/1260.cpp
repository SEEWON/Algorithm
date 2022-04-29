#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int visited[1001]={0};
int line[1001][1001]={0};
int node_num;
int line_num;
int start_node;

//dfs 재귀(스택)로 구현. 노드에서 타고타고타고 들어감!
void dfs(int x) {
  if(visited[x]) return;
  visited[x]=1;

  cout << x << " ";
  for(int i=1;i<=node_num;i++) {
    if(line[x][i]) dfs(i);
  }
}

//bfs 큐로 구현.하나의 노드와 이어져 있는 애들 다 큐에 넣음!
void bfs(int x) {
  queue<int> q;
  q.push(x);
  while(!q.empty()) {
    x = q.front();
    q.pop();
    cout << x << " ";
    for(int i=1;i<=node_num;i++) {
      if(!visited[i] && line[x][i]) {
        q.push(i);
        visited[i]=1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> node_num >> line_num >> start_node;

  int a,b;
  for(int i=0;i<line_num;i++) {
    cin >> a >> b;
    line[a][b]=1;
    line[b][a]=1;
  }
  dfs(start_node);
  for(int i=0;i<1001;i++) {
    visited[i]=0;
  }
  cout << endl;
  //첫 번째 노드는 첨에 방문!
  visited[start_node]=1;
  bfs(start_node);
  return 0;
}