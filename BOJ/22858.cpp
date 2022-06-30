#include <iostream>

using namespace std;
long long D[10001];
long long S[10001];
long long P[10001];

int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> S[i];
  }
  long long input;
  for (int i = 1; i <= N; i++) {
    cin >> input;
    D[i] = input;
  }

  for (int t = 1; t <= N; t++) {  //모든 원소에 대해서
    int now = t;
    int resultIdx;
    for (int it = 0; it < K; it++) {  // K번 섞기를 역행함
      resultIdx = D[now];
      now = resultIdx;
    }
    P[resultIdx] = S[t];
  }

  for (int i = 1; i <= N; i++) {
    cout << P[i] << ' ';
  }

  return 0;
}