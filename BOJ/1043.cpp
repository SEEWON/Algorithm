#include <iostream>
#include <set>

using namespace std;

int party_n, people_n, knows_truth_n;
int party_attendy_n[50] = {0};
int party_attendies[50][50] = {0};
set<int> knows_truth;
int ans = 0;

void solve() {
  for (int i = 0; i < party_n; i++) {
    //한 번 돌면서 knows_truth 업데이트 (간접적으로 듣는 사람 추가)
    bool flag = false;
    for (int j = 0; j < party_attendy_n[i]; j++) {
      // part_attendies 중 진실을 아는 사람이 존재한다면
      if (knows_truth.find(party_attendies[i][j]) != knows_truth.end()) {
        flag = true;
        break;
      }
    }
    if (flag) {
      //해당 파티에 참석한 모든 사람들을 다 knows_truth취급
      for (int j = 0; j < party_attendy_n[i]; j++) {
        knows_truth.insert(party_attendies[i][j]);
      }
      flag = false;
    } else
      continue;
  }

  ans = 0;
  for (int i = 0; i < party_n; i++) {
    //두 번째 돌면서 ans 구하기
    bool flag = false;
    for (int j = 0; j < party_attendy_n[i]; j++) {
      if (knows_truth.find(party_attendies[i][j]) != knows_truth.end()) {
        flag = true;
        break;
      }
    }
    if (flag) {
      flag = false;
      continue;
    } else
      ans++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> people_n >> party_n;
  cin >> knows_truth_n;
  for (int i = 0; i < knows_truth_n; i++) {
    int n;
    cin >> n;
    knows_truth.insert(n);
  }
  for (int i = 0; i < party_n; i++) {
    int n;
    cin >> n;
    party_attendy_n[i] = n;
    for (int j = 0; j < n; j++) {
      cin >> party_attendies[i][j];
    }
  }

  for (int i = 0; i < 50; i++) {
    solve();
  }
  cout << ans << endl;
  return 0;
}