//https://www.geeksforgeeks.org/gocc15-google-swe-online-coding-challenge-internship-2021/?ref=rp
//GOCC 15 Divisibility Count
#include<bits/stdc++.h>
using namespace std;
 
int FindIt (int N, int X, int Y) {
   // Write your code here
   int bigger_one = max(X, Y);
   int smaller_one = bigger_one==X ? Y : X;

   int common_multiple = 0;
   for(int i=1; i<=smaller_one; i++) {
    if(bigger_one * i % smaller_one == 0) {
        common_multiple = bigger_one*i;
        break;
    }
   }
   return pow(10, N)/common_multiple - pow(10, N-1)/common_multiple;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i_arr = 0; i_arr < n; i_arr++)
    {
    	int N, X, Y;
        cin >> N >> X >> Y;
        
        int out_;
        out_ = FindIt(N, X, Y);
        cout << out_ << '\n';
    }
}
    