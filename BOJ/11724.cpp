#include<iostream>
#include<vector>

using namespace std;

vector<int> v[1001];
int check[1001] ={0};

void dfs(int idx) {
  check[idx]=1;
  for(int i=0;i<v[idx].size();i++) {
    if(!check[v[idx][i]]) dfs(v[idx][i]);
  }
}

int main() {
  int ans=0;
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;

  for(int i=0;i<M;i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1;i<=N;i++) {
    if(!check[i]) ans++;
    check[i]=1;
    for(int j=0;j<v[i].size();j++) {
      dfs(v[i][j]);
    }
  }
  cout << ans << endl;

  return 0;
}