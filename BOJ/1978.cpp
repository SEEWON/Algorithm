#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 2) {
      ans++;
      continue;
    }
    for (int j = 2; j < x; j++) {
      if (x % j == 0) break;
      if (j == x - 1) ans++;
    }
  }
  cout << ans << endl;
}