// #include <cstdio>
#include <iostream>

using namespace std;
int arr[301][301];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M, R;
  cin >> N >> M >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  /* N=7 M=8 nail=4
                cornerRT
  ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ ㅁ ㅇ
  ㅇ ㅅ ㅅ ㅅ ㅅ ㅅ ㅅ ㅇ
  ㅇ ㅅ ㅇ ㅇ ㅇ ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅇ ㅅ ㅅ ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅇ ㅇ ㅇ ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅅ ㅅ ㅅ ㅅ ㅅ ㅁ
  ㅇ ㅁ ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ
  cornerLB      cornerRB

  N=5 M=7
  ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ
  ㅇ ㅅ ㅅ ㅅ ㅅ ㅅ ㅇ
  ㅇ ㅅ ㅇ ㅇ ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅅ ㅅ ㅅ ㅅ ㅇ
  ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ ㅇ

  N=6 M=3
  ㅇ ㅇ ㅇ
  ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅇ
  ㅇ ㅅ ㅇ
  ㅇ ㅇ ㅇ
  */

  //배열 돌리기
  int nail;  //몇 겹인지?
  nail = min(N, M) / 2;
  //몇 번 돌릴지
  for (int i = 0; i < R; i++) {
    //몇 겹을 돌릴지
    for (int t = 0; t < nail; t++) {
      int cornerLB, cornerRB, cornerRT, cornerLT;  //모서리 값 담아놓는 변수
      //각 변의 원소 회전
      cornerLB = arr[N - t - 1][t];
      for (int p = N - t - 1; p > t; p--) {
        arr[p][t] = arr[p - 1][t];  //한 칸씩 내림
      }

      cornerRB = arr[N - t - 1][M - t - 1];
      for (int p = M - t - 1; p > t; p--) {
        arr[N - t - 1][p] = arr[N - t - 1][p - 1];  //한 칸씩 오른쪽으로 땡김
      }
      arr[N - t - 1][t + 1] = cornerLB;

      cornerRT = arr[t][M - t - 1];
      for (int p = t; p < N - t - 1; p++) {
        arr[p][M - t - 1] = arr[p + 1][M - t - 1];  //한 칸씩 올림
      }
      arr[N - t - 2][M - t - 1] = cornerRB;

      for (int p = t; p < M - t - 1; p++) {
        arr[t][p] = arr[t][p + 1];  //한 칸씩 왼쪽으로 땡김
      }
      arr[t][M - t - 2] = cornerRT;
    }
  }
  //가운데 한 줄 돌려주도록 구현
  if (min(N, M) % 2) {
    if (N < M) {
      int t = N / 2;
      for (int i = 0; i < R; i++) {
        // arr[t][t]부터 arr[t][M-t]까지
        int corner = arr[t][M - t - 1];
        for (int it = 0; it < M - 2 * t - 1; it++) {
          arr[t][M - t - 1 - it] = arr[t][M - t - 2 - it];
        }
        arr[t][t] = corner;
      }
    } else {
      int t = M / 2;
      for (int i = 0; i < R; i++) {
        // arr[t][t]부터 arr[N-t][t]까지
        int corner = arr[N - t - 1][t];
        for (int it = 0; it < N - 2 * t - 1; it++) {
          arr[N - t - 1 - it][t] = arr[N - t - 2 - it][t];
        }
        arr[t][t] = corner;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j] << ' ';
      // printf("%2d ", arr[i][j]);
    }
    cout << endl;
  }
  return 0;
}