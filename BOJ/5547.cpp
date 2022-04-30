#include<iostream>
#include<queue>

using namespace std;

int R, C;
int arr[102][102][2]={0};   //[0]에는 건물의 여부를, [1]에는 방문여부를 나타냄.
int even[6][2]={{-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int odd[6][2]={{0,-1},{-1,1},{-1,0},{0,1},{1,1},{1,0}};

int bfs(int x, int y) {
  int result=0;
  queue<pair<int, int>> q;
  q.push(make_pair(x,y));

  while(!q.empty()) {
    int currR=q.front().first;
    int currC=q.front().second;
    q.pop();

    //Row가 짝수일 때
    if(currR%2==0) {
      for(int i=0;i<6;i++) {
        int nextR=currR+even[i][0];
        int nextC=currC+even[i][1];
        if(nextR>=0 && nextR<=R+1 && nextC>=0 && nextC<=C+1) {
          //nextR, nextC의 좌표가 흰색 건물인 경우!
          if(arr[nextR][nextC][0]==0 && !arr[nextR][nextC][1]) {
            arr[nextR][nextC][1]=1;
            q.push(make_pair(nextR, nextC));
          } else if(arr[nextR][nextC][0]==1) result++;
        }
      }
    }

    //Row가 홀수일 때
    else {
      for(int i=0;i<6;i++) {
        int nextR=currR+odd[i][0];
        int nextC=currC+odd[i][1];
        if(nextR>=0 && nextR<=R+1 && nextC>=0 && nextC<=C+1) {
          //nextR, nextC의 좌표가 흰색 건물인 경우!
          if(arr[nextR][nextC][0]==0 && !arr[nextR][nextC][1]) {
            arr[nextR][nextC][1]=1;
            q.push(make_pair(nextR, nextC));
          } else if(arr[nextR][nextC][0]==1) result++;
        }
      }
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> C >> R;
  for(int i=1;i<=R;i++) {
    for(int j=1;j<=C;j++) {
      cin >> arr[i][j][0];
    }
  }

  //그래프 좌표는 (1,1)부터 시작하나, 한 칸 더 여유롭게 만들어서 끊어지지 않게 탐색.
  cout << bfs(0,0) << endl;
  return 0;
}