#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long N;
  cin >> N;
  pair<int, int> * arr = new pair<int, int>[N];
  int dp[N+2] = {0};

  for(long long i=1;i<=N;i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  for(long long i=1;i<=N;i++) {
    if(i+arr[i].first<=N+1) dp[i+arr[i].first] = max(dp[i+arr[i].first], dp[i]+arr[i].second);
    //이번 턴에 일을 하지 않은 경우에도, 이제까지 번 돈 더해줌!
    dp[i+1] = max(dp[i], dp[i+1]);
  }

  cout << dp[N+1] << endl;

  return 0;
}