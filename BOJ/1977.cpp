// M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최솟값을 찾는 프로그램을 작성하시오. 예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 완전제곱수는 64, 81, 100 이렇게 총 3개가 있으므로 그 합은 245가 되고 이 중 최솟값은 64가 된다.

#include <iostream>
using namespace std;
int main(void)
{
  int min, max;
  int sqrArr[101];
  int res[100];

  cin >> min;
  cin >> max;

  for (int i = 1; i < 101; i++)
  {
    sqrArr[i - 1] = i * i;
  }

  int j = 0, resPointer = 0;
  while (1)
  {
    if (sqrArr[j] >= min && sqrArr[j] <= max)
    {
      res[resPointer] = sqrArr[j];
      resPointer++;
    }
    if (sqrArr[j] > max)
    {
      break;
    }
    j++;
  }

  if (resPointer == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    int ans = 0;
    for (int i = 0; i < resPointer; i++)
    {
      ans += res[i];
    }
    cout << ans << '\n'
         << res[0] << endl;
  }

  return 0;
}