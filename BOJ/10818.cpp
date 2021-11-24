// N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

#include <iostream>

using namespace std;

int main(void)
{
  int n;
  int number;
  cin >> n;

  int max = -1000000, min = 1000000;

  for (int i = 0; i < n; i++)
  {
    cin >> number;
    if (number > max)
    {
      max = number;
    }
    if (number < min)
    {
      min = number;
    }
  }

  cout << min << " " << max << endl;

  return 0;
}