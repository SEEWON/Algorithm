#include<iostream>

using namespace std;

int arr[11][11]={0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=1;i<=N;i++) {
    for(int j=1;j<=N;j++) {
      cin >> arr[i][j];
    }
  }

  int R_Cor[5]={0,0,1,0,-1};
  int C_Cor[5]={0,1,0,-1,0};
  int ans=3000;
  for(int i=1;i<=N*N;i++) {
    for(int j=i+1;j<=N*N;j++) {
      for(int k=j+1;k<=N*N;k++) {
        int price=0;
        int i_row=i/N+1; int i_col=i%N;
        int j_row=j/N+1; int j_col=j%N;
        int k_row=k/N+1; int k_col=k%N;
        if(i%N==0) {
          i_row=i/N;
          i_col=N;
        }
        if(j%N==0) {
          j_row=j/N;
          j_col=N;
        }
        if(k%N==0) {
          k_row=k/N;
          k_col=N;
        }

        //좌표 유효성 검사
        int flag=0;
        for(int t=0;t<5;t++) {
          //화단 벗어나는 경우
          if(i_row+R_Cor[t]<1 || i_row+R_Cor[t]>N || i_col+C_Cor[t]<1 || i_col+C_Cor[t]>N) {
            flag=1;
            break;
          }
          if(j_row+R_Cor[t]<1 || j_row+R_Cor[t]>N || j_col+C_Cor[t]<1 || j_col+C_Cor[t]>N) {
            flag=1;
            break;
          }
          if(k_row+R_Cor[t]<1 || k_row+R_Cor[t]>N || k_col+C_Cor[t]<1 || k_col+C_Cor[t]>N) {
            flag=1;
            break;
          }
        }
        if(flag) continue;

        //꽃잎이 겹치는 경우
        int flower[11][11]={0};
        for(int t=0;t<5;t++) {
          if(flower[i_row+R_Cor[t]][i_col+C_Cor[t]]==1) {
            flag=1;
            break;
          } else flower[i_row+R_Cor[t]][i_col+C_Cor[t]]=1;
          if(flower[j_row+R_Cor[t]][j_col+C_Cor[t]]==1) {
            flag=1;
            break;
          } else flower[j_row+R_Cor[t]][j_col+C_Cor[t]]=1;
          if(flower[k_row+R_Cor[t]][k_col+C_Cor[t]]==1) {
            flag=1;
            break;
          } else flower[k_row+R_Cor[t]][k_col+C_Cor[t]]=1;
        }
        if(flag) continue;

        //유효한 경우 비용 계산
        for(int t=0;t<5;t++) {
          price+=arr[i_row+R_Cor[t]][i_col+C_Cor[t]];
          price+=arr[j_row+R_Cor[t]][j_col+C_Cor[t]];
          price+=arr[k_row+R_Cor[t]][k_col+C_Cor[t]];
        }

        ans=min(ans, price);
      }
    }
  }

  cout << ans << endl;

  return 0;
}