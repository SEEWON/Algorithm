//https://www.geeksforgeeks.org/google-internship-2020-google-online-challenge1st-coding-round/?ref=rp
//A Special String
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<int> special_nums;

bool IsNegInt(float root_1, float root_2) {
    int check_1 = (int)root_1;
    int check_2 = (int)root_2;
    return (check_1==root_1 || check_2==root_2);
}
 
int FindIt (int n) {
    // Write your code here
    int arr_checked[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j=0; j<n; j++) {
            arr_checked[i][j]=INT_MAX;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j=0; j<n; j++) {
            if(find(special_nums.begin(), special_nums.end(), arr[i][j]) != special_nums.end()) arr_checked[i][j] = 0;
            else {
                int min_diff = INT_MAX;
                for(int k=0; k<special_nums.size(); k++) {
                    int diff = abs(special_nums[k]-arr[i][j]);
                    min_diff = min(min_diff, diff);
                }
                arr_checked[i][j] = min_diff;
            }
        }
    }

    int rtn = INT_MAX;

    for(int i=0;i<n;i++) {
        int sum_row = 0;
        for(int j=0;j<n;j++) {
            sum_row+=arr_checked[i][j];
        }
        rtn = min(sum_row, rtn);
    }

     for(int i=0;i<n;i++) {
        int sum_col = 0;
        for(int j=0;j<n;j++) {
            sum_col+=arr_checked[j][i];
        }
        rtn = min(sum_col, rtn);
    }
    return rtn;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> row(n);
    for(int i = 0; i < n; i++) {
        for(int j=0; j<n; j++) {
            int in;
            cin >> in;
            row[j] = in;
        }
        arr.push_back(row);
    }

    for(int i=1; i<=1011; i++) {
        float root_1 = (-1+sqrt(1+8*i))/4;
        float root_2 = (-1-sqrt(1+8*i))/4;
        if (IsNegInt(root_1, root_2)) {
            special_nums.push_back(i);
        } 
    }

    int out_;
    out_ = FindIt(n);
    cout << out_ << '\n';
    return 0;
}
    