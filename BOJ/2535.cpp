#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
  int country;
  int number;
  int score;
};

bool compare(student a, student b)
{
  return a.score > b.score;
}

int main()
{
  int n;
  cin >> n;

  student arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].country >> arr[i].number >> arr[i].score;
  }

  sort(arr, arr + n, compare);
  if (arr[0].country == arr[1].country && arr[1].country == arr[2].country)
  {
    int i = 3;
    while (1)
    {
      if (arr[i].country != arr[0].country)
      {
        break;
      }
      else
        i++;
    }
    arr[2] = arr[i];
  }

  cout << arr[0].country << ' ' << arr[0].number << '\n'
       << arr[1].country << ' ' << arr[1].number << '\n'
       << arr[2].country << ' ' << arr[2].number << endl;

  return 0;
}