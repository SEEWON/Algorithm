#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> s;
  vector<char> v;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
  }

  int curr = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= curr) {
      for (int j = curr; j <= arr[i]; j++) {
        s.push(j);
        v.push_back('+');
        curr++;
      }
    }
    if (s.top() == arr[i]) {
      s.pop();
      v.push_back('-');
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  for (auto i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}