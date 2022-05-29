#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[21][21] = {0};
int R_cor[4] = {0, 1, 1, 1};
int C_cor[4] = {1, 1, 0, -1};
//바둑알이 있는 경우를 모두 담는 벡터
vector<pair<int, int>> v;
int currCnt;
//계속 갱신되는 ans_case : 정답인 순간에 출력
pair<int, int> ans_case[6];
int exit_code = 0;

bool compare(pair<int, int> a, pair<int, int> b) {
  /*
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
    */
  if (a.second < b.second)
    return true;
  else if (a.second == b.second) {
    if (a.first < b.first)
      return true;
    else
      return false;
  } else
    return false;
}

int dfs(int row, int col, int direction) {
  //같은 방향에서 앞에 돌 있는 경우 pass(이미 셌을거임)
  int prevR = row - R_cor[direction];
  int prevC = col - C_cor[direction];
  if (currCnt == 0) {
    if (prevR >= 0 && prevR <= 18 && prevC >= 0 && prevC <= 18) {
      if (arr[prevR][prevC] == arr[row][col]) return 0;
    }
  }

  int nextR = row + R_cor[direction];
  int nextC = col + C_cor[direction];
  if (nextR < 0 || nextR > 18 || nextC < 0 || nextC > 18 || currCnt > 5)
    return 0;

  if (currCnt == 4) {
    //딱 5개인 경우
    if (arr[nextR][nextC] != arr[row][col]) {
      ans_case[currCnt++] = make_pair(row, col);
      sort(ans_case, ans_case + 5, compare);
      cout << arr[row][col] << '\n'
           << ans_case[0].first + 1 << ' ' << ans_case[0].second + 1 << '\n';
      exit_code = 1;
      return 0;
    } else
      return 0;
  }
  //내용 같은 경우 같은 방향으로 재귀 호출
  if (arr[nextR][nextC] == arr[row][col]) {
    ans_case[currCnt++] = make_pair(row, col);
    dfs(nextR, nextC, direction);
    return 0;
  } else
    return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      int n;
      cin >> n;
      arr[i][j] = n;
      if (n) v.push_back(make_pair(i, j));
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int t = 0; t < 4; t++) {
      currCnt = 0;
      dfs(v[i].first, v[i].second, t);
      if (exit_code) break;
    }
    if (exit_code) break;
  }
  if (!exit_code) cout << 0 << '\n';
  return 0;
}