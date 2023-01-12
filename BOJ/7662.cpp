#include <iostream>
#include <set>
using namespace std;

int T, N;
multiset<int> ms;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    ms.clear();
    for (int j = 0; j < N; j++) {
      char sign;
      int num;
      cin >> sign >> num;
      if (sign == 'I') {
        ms.insert(num);
      } else {
        if (ms.size() == 0) continue;
        if (num == 1) {
          ms.erase(--ms.end());
        } else {
          ms.erase(ms.begin());
        }
      }
    }
    if (ms.size() == 0)
      cout << "EMPTY" << endl;
    else
      cout << *(--ms.end()) << ' ' << *ms.begin() << endl;
  }

  return 0;
}