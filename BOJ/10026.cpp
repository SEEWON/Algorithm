#include <iostream>
#include <queue>
using namespace std;

int N;
char arr[101][101];
bool visited[101][101];
short dir_r[4] = {1, 0, -1, 0};
short dir_c[4] = {0, 1, 0, -1};

void init_visited() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = false;
    }
  }
}

pair<int, int> check_not_visited() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == false) return make_pair(i, j);
    }
  }
  return make_pair(-1, -1);
}

void cover_arr() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == 'G') arr[i][j] = 'R';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  queue<pair<int, int>> q;
  // 정상인이 보는 그림
  init_visited();
  int area_normal = 0;
  while (true) {
    pair<int, int> unvisited = check_not_visited();
    if (unvisited.first == -1) break;
    area_normal++;
    q.push(unvisited);
    visited[unvisited.first][unvisited.second] = true;

    while (!q.empty()) {
      int curr_r = q.front().first;
      int curr_c = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int next_r = curr_r + dir_r[i];
        int next_c = curr_c + dir_c[i];

        if (next_r < 0 || next_r >= N || next_c < 0 || next_r >= N) continue;
        if (visited[next_r][next_c]) continue;
        if (arr[next_r][next_c] != arr[curr_r][curr_c]) continue;
        visited[next_r][next_c] = true;
        q.push(make_pair(next_r, next_c));
      }
    }
  }
  // 적록색약이 보는 그림
  init_visited();
  cover_arr();
  int area_weak = 0;
  while (true) {
    pair<int, int> unvisited = check_not_visited();
    if (unvisited.first == -1) break;
    area_weak++;
    q.push(unvisited);
    visited[unvisited.first][unvisited.second] = true;

    while (!q.empty()) {
      int curr_r = q.front().first;
      int curr_c = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int next_r = curr_r + dir_r[i];
        int next_c = curr_c + dir_c[i];

        if (next_r < 0 || next_r >= N || next_c < 0 || next_r >= N) continue;
        if (visited[next_r][next_c]) continue;
        // 색이 서로 다르고, 둘 중 하나가 B면 넘겨라. (색이 다르되 R&G면 안넘김)
        if (arr[next_r][next_c] != arr[curr_r][curr_c]) continue;
        visited[next_r][next_c] = true;
        q.push(make_pair(next_r, next_c));
      }
    }
  }
  cout << area_normal << ' ' << area_weak << endl;

  return 0;
}
