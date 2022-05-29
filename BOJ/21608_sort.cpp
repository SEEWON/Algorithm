#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int R_cor[4] = {0, 1, 0, -1};
int C_cor[4] = {1, 0, -1, 0};

int like[400][5];
int arr[20][20] = {0};
int checkIdx[401] = {0};

bool compare(pair<pair<int, int>, pair<int, int>> a,
             pair<pair<int, int>, pair<int, int>> b) {
  //이렇게 하면 안됨.
  if (a.second.first != b.second.first)
    return a.second.first < b.second.first;
  else
    a.second.second < b.second.second;
  /*
  if (a.second.first < b.second.first)
    return true;
  else if (a.second.first == b.second.first) {
    if (a.second.second < b.second.second)
      return true;
    else
      return false;
  } else
    return false;
    */
}

//어떤 학생을 몇 번째 위치에 넣었을 때
// first에는 주변 좋아하는 학생 수를, second에는 주변 빈 공간의 수를 리턴
pair<pair<int, int>, pair<int, int>> checkAdjacent(int who, int row, int col) {
  int blank_cnt = 0, like_cnt = 0;
  //인접한 네 좌표에 대해서
  for (int i = 0; i < 4; i++) {
    int nextR = row + R_cor[i];
    int nextC = col + C_cor[i];
    //범위 check
    if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;
    if (arr[nextR][nextC]) {
      for (int j = 1; j <= 4; j++) {
        if (arr[nextR][nextC] == like[who][j]) like_cnt++;
      }
    } else
      blank_cnt++;
  }
  return make_pair(make_pair(like_cnt, blank_cnt), make_pair(row, col));
}

int countSatis() {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int like_cnt = 0;
      for (int t = 0; t < 4; t++) {
        int nextR = i + R_cor[t];
        int nextC = j + C_cor[t];
        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;
        for (int k = 1; k <= 4; k++)
          if (arr[nextR][nextC] == like[checkIdx[arr[i][j]]][k]) like_cnt++;
      }
      if (like_cnt == 1)
        ret++;
      else if (like_cnt == 2)
        ret += 10;
      else if (like_cnt == 3)
        ret += 100;
      else if (like_cnt == 4)
        ret += 1000;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 0; i < N * N; i++) {
    cin >> like[i][0];
    checkIdx[like[i][0]] = i;
    for (int j = 1; j <= 4; j++) cin >> like[i][j];
  }

  //모든 학생을
  for (int i = 0; i < N * N; i++) {
    int max_like = -1;
    vector<pair<pair<int, int>, pair<int, int>>> v_like;
    //모든 칸에 대해서 넣어보기
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        if (arr[row][col]) continue;
        pair<pair<int, int>, pair<int, int>> p;
        p = checkAdjacent(i, row, col);
        if (p.first.first == 0 && p.first.second == 0) continue;
        if (p.first.first > max_like) {
          v_like.clear();
          v_like.push_back(p);
          max_like = p.first.first;
        } else if (p.first.first == max_like) {
          v_like.push_back(p);
        }
      }
    }
    //첫 번째 조건
    if (v_like.size() == 1)
      arr[v_like[0].second.first][v_like[0].second.second] = like[i][0];
    //두 번째 조건
    else {
      int max_blank = -1;
      vector<pair<pair<int, int>, pair<int, int>>> v_blank;
      for (int j = 0; j < v_like.size(); j++) {
        if (v_like[j].first.second > max_blank) {
          v_blank.clear();
          v_blank.push_back(v_like[j]);
          max_blank = v_like[j].first.second;
        } else if (v_like[j].first.second == max_blank) {
          v_blank.push_back(v_like[j]);
        }
      }
      if (v_blank.size() == 1)
        arr[v_blank[0].second.first][v_blank[0].second.second] = like[i][0];
      //세 번째 조건
      else if (v_blank.size() > 1) {
        // cout << "i is: " << i << ' ' << " v size is " << v_blank.size() <<
        // endl; for (int ll = 0; ll < v_blank.size(); ll++) {
        //   cout << "row is: " << v_blank[ll].second.first
        //        << " col is: " << v_blank[ll].second.second << endl;
        // }
        // cout << "sort" << endl;
        sort(v_blank.begin(), v_blank.end(), compare);
        // for (int ll = 0; ll < v_blank.size(); ll++) {
        //   cout << "row is: " << v_blank[ll].second.first
        //        << " col is: " << v_blank[ll].second.second << endl;
        // }
        arr[v_blank[0].second.first][v_blank[0].second.second] = like[i][0];
      }
      //예외 처리: 주변에 친구도 없고, 빈 자리도 없는 경우.
      else {
        int flag = 0;
        for (int p = 0; p < N; p++) {
          for (int q = 0; q < N; q++) {
            if (!arr[p][q]) {
              arr[p][q] = like[i][0];
              flag = 1;
              break;
            }
          }
          if (flag) break;
        }
      }
    }
  }
  cout << countSatis() << endl;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}