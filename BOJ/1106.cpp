#include<iostream>
using namespace std;

//dp테이블은 인덱스만큼의 돈을 써서 얻을 수 있는 최대 benefit
int dp[99999] = {0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int C, N;
  cin >> C >> N;
  //first에는 지불해야 하는 cost, second에는 얻을 수 있는 benefit
  pair<int, int> *arr = new pair<int, int>[N];

  int a,b;
  for(int i=0;i<N;i++) {
    cin >> a >> b;
    arr[i] = make_pair(a, b);
  }

  for(int i=1;;i++) {
    for(int j=0;j<N;j++) {
      //나눠떨어지면!
      if(i%arr[j].first==0) dp[i] = max(dp[i], (i/arr[j].first)*arr[j].second);
      // 한 단계 전이 존재하면!
      if(i-arr[j].first>=0) dp[i] = max(dp[i], dp[i-arr[j].first]+arr[j].second);
    }
    if(dp[i]>=C) {
      cout << i << endl;
      break;
    }
  }

  delete[] arr;
  return 0;
}