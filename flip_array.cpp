#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &a) {
    int n = a.size();
    int sum = 0;
    for(int i:a){
        sum += i;
    }
    vector< vector< bool>> dp( n + 1, vector<bool>(sum + 1, 0));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if( j >= 2*a[i - 1]){
                dp[i][j] = dp[i][j]||dp[i-1][j - 2*a[i - 1]];
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i <=  sum; i++){
        if(dp[n][i]){
            return i;
        }
    }
    return sum;
}

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a);
}