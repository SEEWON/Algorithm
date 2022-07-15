#include <iostream>

using namespace std;
int dp[1001] = {0};
int arr[1001] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i < n + 1; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
  }

  cout << arr[n] << endl;
  return 0;
}