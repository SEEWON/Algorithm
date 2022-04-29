#include<iostream>
#include<vector>
using namespace std;

vector<int> vec[100001];
int v[100001]={0};
int arr[100001]={0};

void dfs(int x) {
  if(v[x]) return;
  v[x]=1;
  for(int i=0;i<vec[x].size();i++) {
    if(!v[vec[x][i]]) {
      arr[vec[x][i]]=x;
      dfs(vec[x][i]);
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int a,b;
  for(int i=0; i<n-1; i++) {
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  dfs(1);

  for(int i=2;i<=n;i++) {
    cout << arr[i] << '\n';
  }
  return 0;
}