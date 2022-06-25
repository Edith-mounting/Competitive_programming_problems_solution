#include <bits/stdc++.h>
using namespace std;
#define int long long

void f(int i, int j, vector<int> &ans, vector< vector< int>> &w, vector<int> &v, int fi){
    if(i >= j){
        return;
    }
    int k = w[i][j];
    // cout << i << " " << j << "\n";
    if((k == i) || (k == j) || (k == 0) || (k == fi)){
        return;
    }
    ans.push_back(v[k]);
    f(i, k, ans, w, v, fi);
    f(k, j, ans, w, v, fi);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 2, 0);
    for(int i = 1; i <= m; i++){
        cin >> v[i];
    }
    v[m + 1] = n;
    sort( v.begin(), v.end());
    vector< vector< int>> dp(m + 2, vector<int>( m + 2, 0));
    vector< vector< int>> w(m + 2, vector<int>( m + 2, 0));
    for(int l = 2; l < m + 2; l++){
        for(int i = 0; i < m + 2; i++){
            int j;
            j = i + l;
            if(j >= m + 2){
                continue;
            }
            dp[i][j] = 10000000000;
            for(int k = i + 1; k < j; k++){
                if(dp[i][j] > dp[i][k] + dp[k][j] + (v[j] - v[i])){
                    dp[i][j] = dp[i][k] + dp[k][j] + (v[j] - v[i]);
                    w[i][j] = k;
                }
            }
        }
    }
    vector<int> ans;
    int start = 0, end = m + 1;
    f( start, end, ans, w, v, m + 1);
    for(int i:ans){
        cout << i << " ";
    }
    cout << "\n";
}

int32_t main(){
    solve();
}