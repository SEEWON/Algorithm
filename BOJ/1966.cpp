#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  int ans[t];

  for (int it=0;it<t;it++) {
    int n, m;
    cin >> n >> m;

    //pair<현재 값, 인덱스> 형태의 자료형으로 queue 구성
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int curr_max=-1;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      q.push(make_pair(x, i));
      pq.push(x);
    }

    int seq=1;
    while(!q.empty()) {
      if(q.front().first==pq.top()) {
        if(m==q.front().second) {
          ans[it] = seq;
          break;
        }
        q.pop();
        pq.pop();
        seq++;
      } else {
        int y_1 = q.front().first;
        int y_2 = q.front().second;
        q.pop();
        q.push(make_pair(y_1, y_2));
      }
    }
  }

  for(int i=0;i<t;i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}
