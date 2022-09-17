#include <iostream>

using namespace std;
int N, M;
int arr[10] = {0};
int ans[10] = {0};
bool visited[10] = {0};

void back_tracking(int curr) {
  if (curr == M) {
    for (int i = 0; i < M; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  else {
    for (int i = 0; i < N; i++) {
      if (visited[i]) continue;
      if (ans[curr - 1] > arr[i]) continue;

      visited[i] = true;
      ans[curr] = arr[i];
      back_tracking(curr + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    arr[i] = i + 1;
  }

  back_tracking(0);

  return 0;
}