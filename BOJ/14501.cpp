#include<iostream>

using namespace std;

int dp[1000]={0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  int T[N+1];
  int P[N+1];

  for(int i=1;i<=N;i++) {
    cin >> T[i] >> P[i];
  }

  for(int i=1;i<=N;i++) {
    dp[i+T[i]-1]=max(dp[i+T[i]-1],dp[i-1]+P[i]);
    dp[i+1]=max(dp[i], dp[i+1]);
  }

  cout << dp[N] << endl;

  return 0;
}