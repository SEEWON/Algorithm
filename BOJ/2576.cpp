#include<iostream>
#include<algorithm>

using namespace std;

int main () {
  int all[7];
  for (int i=0;i<7;i++) {
    cin >> all[i];
  }
  sort(all,all+7);
  int sum=0;
  int oddCnt=0;
  int smallestOddNum;
  for(int i=0;i<7;i++) {
    if(all[i]%2==1) {
      sum+=all[i];
      if(oddCnt==0) {
        smallestOddNum=all[i];
      }
      oddCnt++;
    } else {
      continue;
    }
  }

  if(oddCnt) cout << sum << '\n' << smallestOddNum << endl;
  else cout << -1 << endl;

  return 0;
}