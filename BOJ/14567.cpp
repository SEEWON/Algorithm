#include<iostream>
#include<vector>
using namespace std;

//행이 1001개인 2차원 벡터 생성
vector<int> v[1001];
//방문 여부를 기록하는 배열
int dp[1001]={0,};

int calculate(int n) {
  //선수과목이 없으면 1 리턴
  if(v[n].size()==0) return 1;
  //해당 과목 노드 방문한 적 있다면 그 값 리턴
  if(dp[n]!=0) return dp[n];

  //선수과목의 개수만큼 연산 시행
  for(int i=0;i<v[n].size();i++) {
    //여러 개의 선수과목 중를 모두 만족한 가장 나중 학기에 들어야 함
    dp[n] = max(dp[n], calculate(v[n][i])+1);
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  long M;
  cin >> N >> M;
  int * dp = new int[N+1];
  int a, b;
  for (long i=0; i<M; i++) {
    cin >> a >> b;
    v[b].push_back(a);
  }

  for (int i=1; i<N+1; i++) {
    cout << calculate(i) << ' ';
  }
  cout << endl;

}