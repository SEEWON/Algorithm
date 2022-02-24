#include<iostream>
#include<set>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int aCnt,bCnt;
  set <int> a;
  cin >> aCnt >> bCnt;
  int temp;
  for(int i=0;i<aCnt;i++) {
    cin >> temp;
    a.insert(temp);
  }
  int * b = new int[bCnt];
  for(int i=0;i<bCnt;i++) {
    cin >> b[i];
  }
  for(int i=0;i<bCnt;i++) {
    auto iterator = a.find(b[i]);
    if(iterator==a.end()) continue;
    else a.erase(iterator);
  }
  cout << a.size() << '\n';
  if(a.size()==0) return 0;
  else {
    for(auto i=a.begin();i!=a.end();i++) {
      cout << *i << ' ';
    }
    cout<<'\n';
  }

  delete[] b;
  return 0;
}