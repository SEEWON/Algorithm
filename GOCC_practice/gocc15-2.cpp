//https://www.geeksforgeeks.org/gocc15-google-swe-online-coding-challenge-internship-2021/?ref=rp
//GOCC 15 The maximum XOR value
#include<bits/stdc++.h>
using namespace std;
 
int FindIt (vector<int> arr, int x, int m) {
   // Write your code here
   int n = arr.size();
   int rtn = -1;
   int max_XOR = -1;
   for(int i=0; i<n; i++) {
    if(arr[i]<=m) {
        if(max_XOR < (arr[i]^x)) {
         rtn = arr[i];
         max_XOR = (arr[i]^x);
        }
    }
   }
   return rtn;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr = 0; i_arr < n; i_arr++)
    {
    	cin >> arr[i_arr];
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, m;
        cin >> x >> m;
    
        int out_;
        out_ = FindIt(arr, x, m);
        cout << out_ << '\n';
    }
}
    