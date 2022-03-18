#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int dp[k+1]={0};
  int nums[n];
  for(int i=0;i<n;i++) {
    cin >> nums[i];
  }
  dp[0]=1;
  for(int i=0;i<n;i++) {
    for(int j=1;j<k+1;j++) {
      if(j>=nums[i]) {
        dp[j]=dp[j]+dp[j-nums[i]]; 
      } 
    }
  }
  cout << dp[k] << endl;
  return 0;
}