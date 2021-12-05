#include <iostream>
#include <algorithm>

using namespace std;

class medal
{
private:
  int id;
  int gold;
  int silver;
  int bronze;

public:
  //기본 생성자, 0으로 초기화
  medal()
  {
    id = 0;
    gold = 0;
    silver = 0;
    bronze = 0;
  };

  void setMedal(int _id, int _gold, int _silver, int _bronze)
  {
    id = _id;
    gold = _gold;
    silver = _silver;
    bronze = _bronze;
  };
  int getId()
  {
    return id;
  }
  int showGold()
  {
    return gold;
  }
  int showSilver()
  {
    return silver;
  }
  int showBronze()
  {
    return bronze;
  }
};

bool compare(medal a, medal b)
{
  if (a.showGold() > b.showGold())
    return true;
  else if (a.showGold() == b.showGold())
  {
    if (a.showSilver() > b.showSilver())
      return true;
    if (a.showSilver() == b.showSilver())
    {
      if (a.showBronze() > b.showBronze())
        return true;
    }
  }
}

int main()
{
  int n, resId;
  cin >> n >> resId;

  medal arr[n];
  int id, gold, silver, bronze;
  for (int i = 0; i < n; i++)
  {
    cin >> id >> gold >> silver >> bronze;
    arr[i].setMedal(id, gold, silver, bronze);
  }

  sort(arr, arr + n, compare);

  int resRank(0);
  while (1)
  {
    if (arr[resRank].getId() == resId)
      break;
    else
      resRank++;
  }
  while (1)
  {
    if (resRank == 0)
      break;
    if (arr[resRank].showGold() == arr[resRank - 1].showGold() && arr[resRank].showSilver() == arr[resRank - 1].showSilver() && arr[resRank].showBronze() == arr[resRank - 1].showBronze())
      resRank--;
    else
      break;
  }

  cout << resRank + 1 << endl;

  return 0;
}