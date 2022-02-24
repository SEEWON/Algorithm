#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(void) {
  int N, k;
  string str;
  scanf("%d %d",&N, &k);
  vector <int> v,res;
  int temp;
  for(int i=0;i<N;i++) {
    scanf("%d", &temp);
    getchar();
    v.push_back(temp);
  }
  res = v;
  for(int i=0;i<k;i++) {
    res.clear();
    for(int i=0;i<v.size()-1;i++) {
      res.push_back(v[i+1]-v[i]);
    }
    v.clear();
    v = res;
  }
  cout<<res[0];
  for(int i=1;i<res.size();i++) {
    cout<<','<<res[i];
  }
  cout<<endl;

  return 0;
}