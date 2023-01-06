#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, n;
  cin >> m >> n;
  int arr[n + 1];
  arr[1] = 0;
  for (int i = 2; i <= n; i++) {
    arr[i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; i * j <= n; j++) arr[i * j] = 0;
  }
  for (int i = m; i <= n; i++)
    if (arr[i] != 0) cout << i << '\n';
}