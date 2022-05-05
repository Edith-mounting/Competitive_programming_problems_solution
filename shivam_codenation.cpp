#include <bits/stdc++.h>
using namespace std;
#define int long long


int solve(string s){
    int ans = 0;
    int n = s.length();
    int left_L = 0, right_L = 0;
    int left_R = 0, right_R = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            right_L++;
        }
        else right_R++;
    }
    ans = min( right_L, right_R);
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            right_L--;
        }
        else{
            left_R++;
        }
        ans = min( ans, left_R + right_L);
    }
    return ans;
}
int32_t main(){
    string s;
    cin >> s;
    cout << solve(s) << "\n";
}
