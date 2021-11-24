// 어떤 반에 있는 학생들의 생일이 주어졌을 때, 가장 나이가 적은 사람과 가장 많은 사람을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int num;
  cin >> num;

  string name[num];
  int day[num];
  int month[num];
  int year[num];

  for (int i = 0; i < num; i++)
  {
    cin >> name[i];
    cin >> day[i];
    cin >> month[i];
    cin >> year[i];
  }

  int birthday[num];
  for (int i = 0; i < num; i++)
  {
    birthday[i] = year[i] * 10000 + month[i] * 100 + day[i];
  }

  int youngest = 0, oldest = 0;
  for (int i = 1; i < num; i++)
  {
    if (birthday[i] > birthday[youngest])
    {
      youngest = i;
    }
    if (birthday[i] < birthday[oldest])
    {
      oldest = i;
    }
  }

  cout << name[youngest] << '\n'
       << name[oldest] << endl;

  return 0;
}