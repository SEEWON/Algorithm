#include <iostream>
using namespace std;
int N;
int arr[1001][3];  // 각 열은 색을 나타냄
int dp[1001][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  // 첫 번째 집
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][1];
  dp[0][2] = arr[0][2];

  for (int i = 1; i < N; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
  }

  cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << endl;

  return 0;
}