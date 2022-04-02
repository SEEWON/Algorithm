#include<iostream>
#include<cstring>
using namespace std;

int arr[5001];
int dp[5001][5001];

int solve (int start, int end) {
  if(dp[start][end]==-1) {
    if(start==end) dp[start][end]=0;
    else if(start>end) dp[start][end]=0;
    else if(arr[start]==arr[end]) dp[start][end]=solve(start+1, end-1);
    else dp[start][end] = min(solve(start+1,end)+1,solve(start,end-1)+1);
  } 
  return dp[start][end];
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0;i<N;i++) {
    cin >> arr[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(0, N-1) << endl;

  return 0;
}