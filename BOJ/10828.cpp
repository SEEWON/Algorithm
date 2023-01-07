#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  stack<int> s;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int x;
      cin >> x;
      s.push(x);
    } else if (str == "pop") {
      if (s.empty())
        cout << -1 << '\n';
      else {
        int x = s.top();
        cout << x << '\n';
        s.pop();
      }
    } else if (str == "size") {
      cout << s.size() << '\n';
    } else if (str == "empty") {
      if (s.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (str == "top") {
      if (s.empty())
        cout << -1 << '\n';
      else {
        cout << s.top() << '\n';
      }
    }
  }
}