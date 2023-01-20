#include <iostream>
using namespace std;

int N;
int arr[501][501];
int dp[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  dp[0][0] = arr[0][0];

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] + arr[i][j];
      } else if (j == i) {
        dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
      } else {
        dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, dp[N - 1][i]);
  }
  cout << ans << endl;

  return 0;
}
