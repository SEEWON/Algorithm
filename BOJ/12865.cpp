#include<iostream>
using namespace std;

int dp[110][100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;
  //dp테이블을 만들어서, 행은 물건의 개수-무게
  pair<int,int> *items = new pair<int,int>[N];
  int a, b;

  for (int i=1; i<=N; i++) {
    cin >> a >> b;
    //물건의 무게-가치로 쌍 만들기
    items[i] = make_pair(a, b);
  }
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=K; j++) {
      if(j>=items[i].first) dp[i][j]=max(dp[i-1][j],dp[i-1][j-items[i].first]+items[i].second);
      else dp[i][j] = dp[i-1][j];
    }
  }
  cout << dp[N][K] << endl;

  return 0;
}