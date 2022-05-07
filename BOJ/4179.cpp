#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int R, C;
char **arr;
int Rcor[4] = {0, 0, 1, -1};
int Ccor[4] = {1, -1, 0, 0};
pair<int,int> Jihoon;
vector<pair<int,int>> Fire;

void bfs() {
  int time=0;
  queue<pair<int,int>> JihoonQ;
  JihoonQ.push(Jihoon);

  queue<pair<int,int>> FireQ;
  for(int i=0;i<Fire.size();i++) {
    FireQ.push(Fire[i]);
  }

  while(!JihoonQ.empty()) {
    time++;
    // cout << "Time flows. Time is: " << time << endl;
    // cout << JihoonQ.size() << endl;
    int loopCnt = JihoonQ.size();
    for(int t=0;t<loopCnt;t++) {
      int nowR=JihoonQ.front().first;
      int nowC=JihoonQ.front().second;
      // cout << "Jihoon's nowR is: " << nowR << " nowC is: " << nowC << endl;
      JihoonQ.pop();
      if(arr[nowR][nowC]!='J') continue;

      for(int i=0;i<4;i++) {
        int nextR=nowR+Rcor[i];
        int nextC=nowC+Ccor[i];
        if(nextR<0 || nextR>=R || nextC<0 || nextC>=C) {
          cout << time << endl;
          // cout << "time is: " << time << endl;
          return;
        } 
        if(arr[nextR][nextC]=='#' || arr[nextR][nextC]=='F' || arr[nextR][nextC]=='J') continue;
        else {
          arr[nextR][nextC] = 'J';
          JihoonQ.push(make_pair(nextR,nextC));
          // cout << "Jihoon's nextR is: " << nextR << " nextC is: " << nextC << endl;
        }
      }
    }

    loopCnt = FireQ.size();
    for(int t=0;t<loopCnt;t++) {
      int nowR=FireQ.front().first;
      int nowC=FireQ.front().second;
      // cout << "Fire's nowR is: " << nowR << " nowC is: " << nowC << endl;
      FireQ.pop();

      for(int i=0;i<4;i++) {
        int nextR=nowR+Rcor[i];
        int nextC=nowC+Ccor[i];
        if(nextR<0 || nextR>=R || nextC<0 || nextC>=C || arr[nextR][nextC]=='#' || arr[nextR][nextC]=='F') continue;
        else {
          arr[nextR][nextC] = 'F';
          FireQ.push(make_pair(nextR,nextC));
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main() {

  cin >> R >> C;
  arr = new char*[R];
  for(int i=0;i<R;i++) arr[i] = new char[C];
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      char input;
      cin >> input;
      arr[i][j] = input;
      if(input=='J') Jihoon=make_pair(i,j);
      if(input=='F') Fire.push_back(make_pair(i,j));
    }
  }

  bfs();

  for(int i=0;i<R;i++) delete[]arr[i];
  delete[]arr;

  return 0;
}