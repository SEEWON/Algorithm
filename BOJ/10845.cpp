#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  queue<int> q;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int x;
      cin >> x;
      q.push(x);
    } else if (str == "pop") {
      if (q.empty())
        cout << -1 << '\n';
      else {
        int x = q.front();
        cout << x << '\n';
        q.pop();
      }
    } else if (str == "size") {
      cout << q.size() << '\n';
    } else if (str == "empty") {
      if (q.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (str == "front") {
      if (q.empty())
        cout << -1 << '\n';
      else {
        cout << q.front() << '\n';
      }
    } else if (str == "back") {
      if (q.empty())
        cout << -1 << '\n';
      else {
        cout << q.back() << '\n';
      }
    }
  }
}