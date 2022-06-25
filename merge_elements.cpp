#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
    int n = a.size();
    int inf = 2000000;
    vector< vector< int>> dp( n, vector<int>(n, inf));

    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
    }

    for(int l = 1; l < n; l++){
        for(int i = 0; i < n; i++){
            int j = i + l;
            if(j < n){
                int x = 0;
                for(int k = i; k < j; k++){
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j]);
                    x += a[k];
                }
                dp[i][j] += x + a[j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[0][n - 1];
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