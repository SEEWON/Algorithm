#include <math.h>

#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int ans = 0;
  int N, r, c;
  cin >> N >> r >> c;

  for (int i = N - 1; i > 0; i--) {
    int pivot = pow(2, i);
    ans += (r / pivot) * pivot * (pivot * 2);
    ans += (c / pivot) * pivot * pivot;
    r %= pivot;
    c %= pivot;
  }

  if (r == 0 && c == 0)
    ans += 0;
  else if (r == 0 && c == 1)
    ans += 1;
  else if (r == 1 && c == 0)
    ans += 2;
  else if (r == 1 && c == 1)
    ans += 3;

  cout << ans << endl;
  return 0;
}

/*
  처음 idea
  ans += (r / 4) * 4 * pow(2, N);  //위에 부분 잘라먹기
  ans += (c / 4) * 16;             //왼쪽 부분 잘라먹기
  //이제 4*4 기준으로 생각할 수 있다.
  r = r % 4;
  c = c % 4;
  ans += (r / 2) * 8;
  ans += (c / 2) * 4;
  //이제 2*2 기준으로!
  r = r % 2;
  c = c % 2;
*/