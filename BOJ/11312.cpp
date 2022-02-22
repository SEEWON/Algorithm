#include<iostream>
#include<vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  vector <long int> v;
  cin >> T;
  for(int i=0;i<T;i++) {
    long int A, B;
    cin >> A >> B;
    long int n = A/B;
    long int res=0;
    for(n;n!=0;n--) {
      res+= n+n-1;
    }
    v.push_back(res);
  }

  for(int i=0;i<v.size();i++) {
    cout << v[i] << endl;
  }

  return 0;
}