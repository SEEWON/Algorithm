#include<iostream>
#include<vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N,M;
  cin >> N >> M;
  vector <int> badCombination[N+1];


  for(int i=0;i<M;i++) {
    int a,b;
    cin >> a >> b;
    badCombination[a].push_back(b);
    badCombination[b].push_back(a);
  }

  int cnt=0;
  for(int i=1;i<=N;i++) {
    for(int j=i+1;j<=N;j++) {
      for(int k=j+1;k<=N;k++) {
        int flag=0;
        for(int t=0;t<badCombination[i].size();t++) {
          if(badCombination[i][t]==j || badCombination[i][t]==k) flag=1;
        }
        for(int t=0;t<badCombination[j].size();t++) {
          if(badCombination[j][t]==i || badCombination[j][t]==k) flag=1;
        }
        // for(int t=0;t<badCombination[k].size();t++) {
        //   if(badCombination[k][t]==i || badCombination[k][t]==j) flag=1;
        // }
        if(!flag) cnt++;
      }
    }
  }
  cout << cnt << endl;


  return 0;
}