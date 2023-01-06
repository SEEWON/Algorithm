#include <climits>
#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int ans = INT_MAX;

  for (int i = 0; i < n + 1 - 8; i++) {
    for (int j = 0; j < m + 1 - 8; j++) {
      int tmp_1 = 0;  // 시작점 칸 색 쓸 경우
      int tmp_2 = 1;  // 시작점 칸 색 안 쓸 경우
      for (int r = 0; r < 8; r++) {
        for (int s = 0; s < 8; s++) {
          if (r == 0 && s == 0) continue;
          if ((r + s) % 2 == 0) {
            if (arr[i][j] != arr[i + r][j + s]) tmp_1++;
            if (arr[i][j] == arr[i + r][j + s]) tmp_2++;
          } else {
            if (arr[i][j] == arr[i + r][j + s]) tmp_1++;
            if (arr[i][j] != arr[i + r][j + s]) tmp_2++;
          }
        }
      }
      ans = min(ans, min(tmp_1, tmp_2));
    }
  }
  cout << ans << endl;
}
