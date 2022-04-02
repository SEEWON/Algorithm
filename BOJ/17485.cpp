#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  int arr[N][M];
  int dp[N][M][3] = {0}; // 0:왼쪽 1:가운데 2:오른쪽
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cin >> arr[i][j];
    }
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      dp[i][j][0]=100000;
      dp[i][j][1]=100000;
      dp[i][j][2]=100000;
    }
  }
  for(int j=0;j<M;j++) {
    dp[0][j][0] = arr[0][j];
    dp[0][j][1] = arr[0][j];
    dp[0][j][2] = arr[0][j];
  }
  int ans=100000;
  for(int i=1;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(j!=0) dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + arr[i][j];       //왼쪽위에서 온 경우
      dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + arr[i][j];                    //가운데 위에서 온 경우
      if(j!=M-1) dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + arr[i][j];     //오른쪽 위에서 온 경우
    }
  }
  for(int j=0; j<M; j++) {
    ans = min(ans, dp[N-1][j][0]);
    ans = min(ans, dp[N-1][j][1]);
    ans = min(ans, dp[N-1][j][2]);
  }

  cout << ans << endl;
  
  return 0;
}