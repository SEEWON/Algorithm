#include<iostream>

using namespace std;

int main() {

  int n, a=0, b=0;
  cin >> n;
  int a_score, b_score;
  for (int i=0;i<n;i++) {
    cin >> a_score >> b_score;
    if(a_score > b_score) {
      a++;
    } else if (b_score > a_score) {
      b++;
    }
  }
  cout << a << ' ' << b << endl;
  return 0;
}