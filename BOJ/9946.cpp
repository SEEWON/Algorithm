#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main (){
  string a, b;
  vector <int> v;
  for(int i=0;; i++) {
    cin >> a;
    cin >> b;
    if(a=="END" && b=="END") break;
    //이렇게 해도 될듯? compare함수와 ==연산자가 비슷하게 사용된다고 한다.
    // if(a.compare("END") + b.compare("END") == 0) break;
    else {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      if(a==b) v.push_back(1); // 알파벳이 일치하는 경우
      else v.push_back(0); // 알파벳이 일치하지 않는 경우
    }
  }

  for(int i=0; i<v.size(); i++) {
    cout << "Case " << i+1 << ':';
    if(v[i]==1) cout << " same" << endl;
    else cout << " different" << endl;
  }

  return 0;
}