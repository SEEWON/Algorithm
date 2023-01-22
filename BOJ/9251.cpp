#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str1;
  string str2;
  cin >> str1 >> str2;
  int len1 = str1.length();
  int len2 = str2.length();
  int curr = 0;

  // dp배열의 0행, 0열은 0을 사용하기 위해 loop 1부터!
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      curr = max(dp[i - 1][j], dp[i][j - 1]);
      if (str1.at(i - 1) == str2.at(j - 1)) {
        curr = dp[i - 1][j - 1] + 1;
      }
      dp[i][j] = curr;
    }
  }
  cout << dp[len1][len2] << endl;
  return 0;
}