#include <iostream>
#include <vector>
using namespace std;

int arr[366] = {0};

int main() {
  int N;
  cin >> N;
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    for (int j = a; j <= b; j++) {
      arr[j]++;
    }
  }
  //구간에 대한 MAX값 구해서 답 계산
  int ans = 0;
  int currDay = 0;
  int currMax = 0;
  for (int i = 1; i <= 365; i++) {
    if (arr[i] == 0) {
      ans += currMax * (i - currDay - 1);
      currDay = i;
      currMax = 0;
    } else {
      currMax = max(arr[i], currMax);
    }
  }
  ans += currMax * (365 - currDay);

  cout << ans << endl;
  return 0;
}