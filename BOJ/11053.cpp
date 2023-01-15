#include <iostream>
using namespace std;

int N;
int arr[1001];
int LIS[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  LIS[N - 1] = 1;
  for (int i = N - 2; i >= 0; i--) {
    int temp = -1;
    for (int j = i; j < N; j++) {
      if (arr[i] < arr[j]) {
        temp = max(temp, LIS[j] + 1);
      } else
        temp = max(temp, 1);
    }
    LIS[i] = temp;
  }
  int ans = -1;
  for (int i = 0; i < N; i++) ans = max(ans, LIS[i]);
  cout << ans << endl;
  return 0;
}