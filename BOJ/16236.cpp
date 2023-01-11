#include <climits>
#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[21][21];
int dist[21][21];
bool visited[21][21];
bool eatable[21][21];
pair<int, int> shark;
int shark_size;
int fish_eaten;
int shark_stayed;
int dist_with_shark;
queue<pair<int, int>> q;

void init() {
  dist_with_shark = INT_MAX;
  while (!q.empty()) q.pop();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = 0;
      visited[i][j] = false;
      eatable[i][j] = false;
    }
  }
}

int check_what_to_eat() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (eatable[i][j]) {
        fish_eaten++;
        arr[i][j] = 0;
        shark = make_pair(i, j);
        shark_stayed += dist[i][j];
        if (fish_eaten == shark_size) {
          fish_eaten = 0;
          shark_size++;
        }
        return 0;
      }
    }
  }
  return 1;
}

void bfs() {
  q.push(shark);
  visited[shark.first][shark.second] = true;

  // 위쪽, 왼쪽 방향의 물고기에 우선순위가 있으므로
  // 방향 위, 왼, 오른, 아래 순
  int dir_r[4] = {-1, 0, 0, 1};
  int dir_c[4] = {0, -1, 1, 0};
  while (!q.empty()) {
    int curr_r = q.front().first;
    int curr_c = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_r = curr_r + dir_r[i];
      int next_c = curr_c + dir_c[i];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
      if (visited[next_r][next_c]) continue;

      if (arr[next_r][next_c] > shark_size)
        continue;
      else {
        q.push(make_pair(next_r, next_c));
        visited[next_r][next_c] = true;
        dist[next_r][next_c] = dist[curr_r][curr_c] + 1;
        // 먹을 수 있는 물고기 발견
        if (arr[next_r][next_c] > 0 && arr[next_r][next_c] < shark_size) {
          if (dist[next_r][next_c] <= dist_with_shark) {
            dist_with_shark = dist[next_r][next_c];
            eatable[next_r][next_c] = true;
          }
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int in;
      cin >> in;
      arr[i][j] = in;
      if (in == 9) {
        shark.first = i;
        shark.second = j;
        arr[i][j] = 0;
      }
    }
  }

  shark_size = 2;

  while (1) {
    init();
    bfs();
    int rtn = check_what_to_eat();
    if (rtn) break;
  }
  cout << shark_stayed << endl;

  return 0;
}