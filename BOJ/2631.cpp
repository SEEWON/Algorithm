#include<iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int * arr = new int[n];
  int * dp = new int[n];
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  int flag=0;
  //최장 증가 부분 수열, LIS 알고리즘
  for (int i=0;i<n;i++) {
    //부분수열 최소 길이는 1개니까, 1로 초기화
    dp[i]=1;
    //시작부터 i번째 idx까지 부분수열 중 증가하는 수열만을 세어 줌
    for(int j=0;j<i;j++) {
      if(arr[j]<arr[i] && dp[j]+1>dp[i]) {
        dp[i]++;
        //flag에 최대값 저장
        if(dp[i]>flag) flag=dp[i];
      }
    }
  }
  cout << n-flag << endl;   

  return 0;
}