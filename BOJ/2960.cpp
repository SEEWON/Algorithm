#include<iostream>
#include<vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  vector <int> v;
  cin >> n >> k;
  for(int i=2;i<n+1;i++) {
    v.push_back(i);
  }
  int i=1;
  int res;
  while(1) {
    //find(v.begin(),v.end(),number) 활용해서 찾거나..map써도 조을듯
    //지우는 수 찾기
    if(i==k) {
      cout << res << endl;
      break;
    } else {

      i++;
    }
  }
    

  return 0;
}