#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int T;
  cin >> T;
  int **score = new int*[T];
  for (int i=0; i<T; i++) {
    score[i] = new int[5];
  }

  for (int i=0; i<T; i++) {
    cin >> score[i][0] >> score[i][1] >> score[i][2] >> score[i][3] >> score[i][4];
  }

  for (int i=0; i<T; i++) {
    sort(score[i], score[i]+5);
      if(score[i][3]-score[i][1]>=4) {
        cout << "KIN" << endl;
      } else {
        cout << score[i][1]+score[i][2]+score[i][3] << endl;
      }
  }

  for (int i=0; i<T; i++) {
    delete[] score[i];
  }
  delete[] score;


  return 0;
}