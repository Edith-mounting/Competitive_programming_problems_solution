#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int i, vector<vector<int>> &adj, vector<int> &ans){

    for(int j:adj[i]){
        dfs(j, adj, ans);
        ans[i] += 1 + ans[j];
    }
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int x;
    for(int i = 2; i <= n; i++){
        cin >> x;
        adj[x].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    dfs( 1, adj, ans);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int32_t main(){
    solve();
}
