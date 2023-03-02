//https://www.geeksforgeeks.org/gocc15-googles-online-challenge-for-internship-india/?ref=rp
//GOCC 15 Special String
#include<bits/stdc++.h>
using namespace std;
 
int FindIt (int n, vector<char> arr) {
   // Write your code here
   int pivot = n/2-1;
   sort(arr.begin(), arr.begin()+pivot);
   sort(arr.begin()+pivot+1, arr.end());
   
   int i = pivot;
   int j = pivot+1;
   int rtn = INT_MAX;
   int cnt=0;

   // in case i<j
   while(i>-1 && *(arr.begin()+i)>=*(arr.begin()+j)) {
    cnt++;
    i--;
   }
   rtn = min(rtn, cnt);
   i = pivot;
   cnt=0;

   while(j<n && *(arr.begin()+i)>=*(arr.begin()+j)) {
    cnt++;
    j++;
   }
   rtn = min(rtn, cnt);
   j = pivot+1;
   cnt=0;

   // in case i>j
   i=0;
   j=n-1;
   while(i<pivot+1 && *(arr.begin()+i)<=*(arr.begin()+j)) {
    cnt++;
    i++;
   }
   rtn = min(rtn, cnt);
   i = 0;
   cnt=0;

   while(j>pivot && *(arr.begin()+i)<=*(arr.begin()+j)) {
    cnt++;
    j--;
   }
   rtn = min(rtn, cnt);
   j = n-1;
   cnt=0;

   // in case i=j
   sort(arr.begin(), arr.end());
   int max_seq = 1;
   int curr_seq = 1;
   char curr = arr[0];

   for(int i=1;i<n;i++) {
    if(arr[i]==curr) {
        curr_seq++;
    } else {
        max_seq = max(max_seq, curr_seq);
        curr_seq=1;
        curr = arr[i];
    }
   }
   max_seq = max(max_seq, curr_seq);
   cnt = n - max_seq;
   rtn = min(rtn, cnt);

   return rtn;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> arr(n);
    for(int i_arr = 0; i_arr < n; i_arr++)
    {
    	cin >> arr[i_arr];
    }
 
    int out_;
    out_ = FindIt(n, arr);
    cout << out_;
}