#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int H,W;
char arr[101][101] = {0};
int Xcor[4] = {1,0,-1,0};
int Ycor[4] = {0,1,0,-1};
queue<pair<int, int>> q;

int bfs() {
  int cnt=0;
  for(int m=0;m<H;m++) {
    for(int n=0;n<W;n++) {
      if(arr[m][n]=='#') {
        q.push(make_pair(m,n));
        cnt++;
      }
      else continue;
      while(!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        arr[nowY][nowX]=-1;

        for(int i=0;i<4;i++) {
          int nextX=nowX+Xcor[i];
          int nextY=nowY+Ycor[i];
          if(nextX>=0 && nextX<W && nextY>=0 && nextY<H && arr[nextY][nextX]!=-1) {
            if(arr[nextY][nextX]=='#') q.push(make_pair(nextY,nextX));
            arr[nextY][nextX]=-1;
          }
        }
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  vector<int> ans;
  for(int t=0;t<T;t++) {
    cin >> H >> W;
    for(int j=0;j<H;j++) {
      for(int k=0;k<W;k++) {
        cin >> arr[j][k];
      }
    }
    
    ans.push_back(bfs());

    for(int j=0;j<H;j++) {
      for(int k=0;k<W;k++) {
        arr[j][k]=0;
      }
    }
  }

  for(int i=0;i<ans.size();i++) {
    cout << ans[i] << endl;
  }

  return 0;
}