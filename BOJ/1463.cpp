#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int dp[N+1]={0};

  dp[2] = 1;
  dp[3] = 1;
  if(N>3) {
    for(int i=4;i!=N+1;i++) {
      if(i%2!=0 && i%3!=0) {
        //2로도, 3으로도 나눠지지 않는 경우
        dp[i] = dp[i-1]+1;
      } else if (i%2==0 && i%3!=0) {
        //2로만 나눠지는 경우
        dp[i] = min(dp[i/2] + 1,dp[i-1]+1);
      } else if (i%2!=0 && i%3==0) {
        //3으로만 나눠지는 경우
        dp[i] = min(dp[i/3] + 1,dp[i-1]+1);
      } else if (i%2==0 && i%3==0) {
        //2, 3으로 모두 나누어지는 경우
        dp[i] = min(dp[i/3] + 1,dp[i/2]+1);
      }
    }
  }
  cout << dp[N] << endl;

  return 0;
}