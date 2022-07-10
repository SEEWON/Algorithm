#include <iostream>

using namespace std;

string str;
int len;
int visited[100] = {0};

void print() {
  for (int i = 0; i < len; i++)
    if (visited[i]) cout << str[i];
  cout << endl;
}

int find_smallest_idx(int start, int end) {
  char min = 'Z' + 1;
  int min_idx = -1;
  for (int i = start; i < end; i++) {
    if (!visited[i] && str[i] < min) {
      min = str[i];
      min_idx = i;
    }
  }
  return min_idx;
}

int recursive(int start, int end) {
  int pivot = find_smallest_idx(start, end);
  if (pivot == -1) return 0;
  visited[pivot] = 1;
  print();
  recursive(pivot + 1, end);
  recursive(start, pivot);
  return 0;
}

int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);

  // cin >> str;
  getline(cin, str);
  len = str.length();

  recursive(0, len);
  return 0;
}