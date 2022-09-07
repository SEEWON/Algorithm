#include <climits>
#include <iostream>

using namespace std;

short arr[100001][3] = {0};
int MAX = -1;
int MIN = INT_MAX;
int T;

void max_dp(short start) {
  int temp1 = 0, temp2 = 0, temp3 = 0;
  int max1 = 0, max2 = 0, max3 = 0;
  if (start == 0) {
    max1 = temp1 = arr[0][0];
  } else if (start == 1) {
    max2 = temp2 = arr[0][1];
  } else {
    max3 = temp3 = arr[0][2];
  }
  for (int i = 1; i < T; i++) {
    temp1 = max(max1, max2) + arr[i][0];
    temp2 = max(max(max1, max2), max3) + arr[i][1];
    temp3 = max(max2, max3) + arr[i][2];
    max1 = temp1;
    max2 = temp2;
    max3 = temp3;
  }

  MAX = max(temp1, MAX);
  MAX = max(temp2, MAX);
  MAX = max(temp3, MAX);
}

void min_dp(short start) {
  int temp1 = 10, temp2 = 10, temp3 = 10;
  int min1 = 10, min2 = 10, min3 = 10;
  if (start == 0) {
    min1 = temp1 = arr[0][0];
  } else if (start == 1) {
    min2 = temp2 = arr[0][1];
  } else {
    min3 = temp3 = arr[0][2];
  }
  for (int i = 1; i < T; i++) {
    temp1 = min(min1, min2) + arr[i][0];
    temp2 = min(min(min1, min2), min3) + arr[i][1];
    temp3 = min(min2, min3) + arr[i][2];
    min1 = temp1;
    min2 = temp2;
    min3 = temp3;
  }

  MIN = min(temp1, MIN);
  MIN = min(temp2, MIN);
  MIN = min(temp3, MIN);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  // arr = new short *[T];
  // for (int i = 0; i < T; i++) {
  //   arr[i] = new short[3];
  // }
  for (int i = 0; i < T; i++) {
    for (int it = 0; it < 3; it++) {
      arr[i][it] = 0;
    }
  }
  for (int i = 0; i < T; i++) {
    for (int it = 0; it < 3; it++) {
      cin >> arr[i][it];
    }
  }

  max_dp(0);
  max_dp(1);
  max_dp(2);

  min_dp(0);
  min_dp(1);
  min_dp(2);
  cout << MAX << ' ' << MIN << endl;
  return 0;
}