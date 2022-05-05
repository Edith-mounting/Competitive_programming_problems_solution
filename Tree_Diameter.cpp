#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> dfs(int i, vector<vector<int>> &adj, int par){
    int maxi = 0, node = i;
    pair<int , int> temp;
    for(int j:adj[i]){
        if(j != par){
            temp = dfs(j, adj, i);
            if(temp.first + 1 >= maxi){
                maxi = temp.first + 1;
                node = temp.second;
            }
            // cout << maxi << " " << j << "\n";
        }
    }
    return {maxi, node};
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int a,b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int, int> temp = dfs( 1, adj, -1);
    cout << dfs(temp.second, adj, -1).first<< "\n";
}
int32_t main(){
    solve();
}
