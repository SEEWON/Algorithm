#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> freq_v;
//-4000~4000의 배열
int arr[8001] = {0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  int avg = 0;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    avg += x;
    v.push_back(x);
  }
  avg = round((double)avg / t);

  sort(v.begin(), v.end());
  for (int i = 0; i < t; i++) {
    arr[v[i] + 4000]++;
  }
  int freq = 0;
  for (int i = 0; i < 8001; i++) {
    if (arr[i] > freq) {
      freq = arr[i];
      freq_v.clear();
      freq_v.push_back(i - 4000);
    } else if (arr[i] == freq) {
      freq_v.push_back(i - 4000);
    }
  }

  int freq_val;
  if (freq_v.size() == 1)
    freq_val = freq_v[0];
  else {
    sort(freq_v.begin(), freq_v.end());
    freq_val = freq_v[1];
  }

  cout << avg << '\n';
  cout << v[t / 2] << '\n';
  cout << freq_val << '\n';
  cout << v[t - 1] - v[0] << '\n';
}