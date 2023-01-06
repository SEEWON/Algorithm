#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  vector<short> v;
  for (int i = 0; i < t; i++) {
    stack<char> s;
    string str;
    cin >> str;
    for (int j = 0; j < str.length(); j++) {
      char curr = str.at(j);
      if (curr == ')') {
        if (!s.empty()) {
          if (s.top() == '(') s.pop();
        } else {
          s.push(')');
        }
      } else {
        s.push('(');
      }
    }
    if (s.empty())
      v.push_back(0);
    else
      v.push_back(1);
  }
  for (auto i = 0; i < v.size(); i++) {
    if (v[i] == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}