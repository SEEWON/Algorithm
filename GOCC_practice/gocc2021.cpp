//https://www.geeksforgeeks.org/googles-online-challenge-for-2021-intern-india-experience/?ref=rp
// Unspecified Words
#include<bits/stdc++.h>
using namespace std;
 
int FindIt (vector<string> v, int len, string str) {
   // Write your code here
   map<int, char> m;
   for(int i=0;i<len;i++) {
    if(str.at(i)!='?') m.insert({i, str.at(i)});
   }

   int rtn=0;
   bool flag=false;
   for(int i=0;i<v.size();i++) {
    flag = false;
    for(auto j=m.begin();j!=m.end();j++) {
        if(v[i].at((*j).first)!=(*j).second) {
            flag=true;
            break;
        }
    }
    if(!flag) rtn++;
   }
   return rtn;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, len;
    cin >> n >> len;

    vector<string> v(n);

    for(int i = 0; i < n; i++)
    {
    	string str;
        cin >> str;
        v[i] = str;
    }

    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        int out_;
        out_ = FindIt(v, len, str);
        cout << out_ << '\n';
    }
    return 0;
}
    