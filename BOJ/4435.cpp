#include<iostream>
#include<vector>

using namespace std;

int main () {
  int T;
  int g1, g2, g3, g4, g5, g6;
  int s1, s2, s3, s4, s5, s6, s7;
  vector <int> v;
  cin >> T;
  for (int i=0;i<T;i++) {
    cin >> g1 >> g2 >> g3 >> g4 >> g5 >> g6;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
    int gsum = g1 + g2*2 + g3*3 + g4*3 + g5*4 + g6*10;
    int ssum = s1 + s2*2 + s3*2 + s4*2 + s5*3 + s6*5 + s7*10;
    if(gsum > ssum) v.push_back(1);
    else if (gsum < ssum) v.push_back(-1);
    else v.push_back(0);
  }

  for(int i=0;i<T;i++) {
    cout << "Battle " << i+1 << ':';
    if(v[i] == 1) cout << " Good triumphs over Evil" << endl;
    if(v[i] == 0) cout << " No victor on this battle field" << endl;
    if(v[i] == -1) cout << " Evil eradicates all trace of Good" << endl;
  }

  return 0;
}