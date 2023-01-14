#include <iostream>
#include <vector>
using namespace std;
int T, n;
int arr[2][100001];
int dp[2][100001];
vector<int> ans;

int opposite(int n) {
  if (n == 0)
    return 1;
  else
    return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      arr[0][j] = 0;
      arr[1][j] = 0;
      dp[0][j] = 0;
      dp[1][j] = 0;
    }
    for (int j = 0; j < n; j++) {
      cin >> arr[0][j];
    }
    for (int j = 0; j < n; j++) {
      cin >> arr[1][j];
    }

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];

    dp[0][1] = arr[1][0] + arr[0][1];
    dp[1][1] = arr[0][0] + arr[1][1];

    for (int j = 2; j < n; j++) {
      dp[0][j] = max(dp[1][j - 1] + arr[0][j], dp[1][j - 2] + arr[0][j]);
      dp[1][j] = max(dp[0][j - 1] + arr[1][j], dp[0][j - 2] + arr[1][j]);
    }

    if (dp[0][n - 1] > dp[1][n - 1])
      ans.push_back(dp[0][n - 1]);
    else
      ans.push_back(dp[1][n - 1]);
  }
  for (int i = 0; i < T; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
