#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> v;

bool compare(string a, string b) {
  if (a.length() != b.length())
    return a.length() < b.length();
  else
    return a < b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    v.push_back(str);
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < N; i++) {
    if (i > 0)
      if (v[i] == v[i - 1]) continue;
    cout << v[i] << '\n';
  }

  return 0;
}