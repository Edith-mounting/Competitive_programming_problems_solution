#include <bits/stdc++.h>
using namespace std;

int adjacent(vector<vector<int> > &a) {
    int n = a[0].size();
    int ans = 0;
    vector<vector<int>> dp( 2, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[0][i] = a[0][i];
            dp[1][i] = a[1][i];
        }
        else if(i == 1){
            // dp[i][0] = max( a[i][0], max(a[i - 1][0], a[i - 1][1]));
            dp[0][i] = max( a[0][i], max(a[0][i - 1], a[1][i - 1]));
            // dp[i][1] = max( a[i][1], max(a[i - 1][1], a[i - 1][0]));
            dp[1][i] = max( a[1][i], max(a[1][i - 1], a[0][i - 1]));
        }
        else{
            // dp[i][0] = max( max(dp[i - 1][0], dp[i - 1][1]), max(dp[i - 2][0], dp[i - 2][1]) + a[i][0]);
            dp[0][i] = max( max(dp[0][i - 1], dp[0][i - 1]), max(dp[0][i - 2], dp[1][i - 2]) + a[0][i]);
            // dp[i][1] = max( max(dp[i - 1][1], dp[i - 1][0]), max(dp[i - 2][1], dp[i - 2][0]) + a[i][1]);
            dp[1][i] = max( max(dp[1][i - 1], dp[0][i - 1]), max( dp[1][i - 2], dp[0][i - 2]) + a[1][i]);
        }
        ans = max( ans, max( dp[0][i], dp[1][i]));
        // cout << dp[0][i] << " " << dp[1][i] << "\n";
    }
    return ans;
}
int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> a( 2, vector<int>(n, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << adjacent(a);
}
