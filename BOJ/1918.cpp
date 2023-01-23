#include <iostream>
#include <stack>
using namespace std;

int priority(char curr) {
  if (curr == '+' || curr == '-') {
    return 1;
  } else if (curr == '*' || curr == '/') {
    return 2;
  } else if (curr == '(') {
    return 0;
  } else if (curr == ')') {
    return 0;
  }
}

stack<char> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;
  int len = str.length();
  for (int i = 0; i < len; i++) {
    char curr = str.at(i);
    if (curr >= 'A' && curr <= 'Z')
      cout << curr;
    else if (curr == '(')
      s.push(curr);
    else if (curr == ')') {
      while (s.top() != '(') {
        cout << s.top();
        s.pop();
      }
      s.pop();
    } else {
      int curr_p = priority(curr);
      if (s.empty())
        s.push(curr);
      else if (priority(s.top()) < curr_p)
        s.push(curr);
      else {
        while (!s.empty() && priority(s.top()) >= curr_p) {
          if (s.top() != '(' && s.top() != ')') cout << s.top();
          s.pop();
        }
        s.push(curr);
      }
    }
  }
  while (!s.empty()) {
    if (s.top() != '(' && s.top() != ')') cout << s.top();
    s.pop();
  }

  return 0;
}
