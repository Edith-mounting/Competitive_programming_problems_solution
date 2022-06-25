#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> adj;
vector<int> ord;
vector<int> child;
void dfs( int i, int par){
    for(int j:adj[i]){
        if(j != par){
            dfs( j, i);
            child[i] += child[j];
        }
    }
    child[i]++;
}
int f(int i, int par){
    if(adj[i].size() == 1){
        return 0;
    }
    if(adj[i].size() == 2){
        if(adj[i][0] == par){
            return (child[adj[i][1]] - 1);
        }
        else{
            return (child[adj[i][0]] - 1);
        }
    }
    if(adj[i][0] == par){
        return max( child[adj[i][1]] - 1 + f(adj[i][2], i),
                    child[adj[i][2]] - 1 + f(adj[i][1], i));
    }
    else if(adj[i][1] == par){
        return max( child[adj[i][0]] - 1 + f(adj[i][2], i),
                    child[adj[i][2]] - 1 + f(adj[i][0], i));
    }
    return max( child[adj[i][1]] - 1 + f(adj[i][0], i),
                    child[adj[i][0]] - 1 + f(adj[i][1], i));
}
void solve(){
    cin >> n;
    adj.clear();
    ord.clear();
    child.clear();
    adj.resize(n + 1);
    ord.resize(n + 1, 0);
    child.resize(n + 1, 0);
    int v,u;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        ord[v]++, ord[u]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs( 1, 0);
    // cout << n << " ";
    // for(int i = 1; i <= n; i++){
    //     cout << child[i] << " ";
    // }
    // cout << "\n";
    int i = 1,j,k;
    int ans = 0;
    int par = -1;
    if(adj[i].size() == 1){
        ans =  (child[adj[i][0]] - 1);
        cout << ans << "\n";
        return ;
    }
    ans = max( child[adj[i][0]] - 1 + f(adj[i][1], i),
                child[adj[i][1]] - 1 + f(adj[i][0], i));
    cout << ans <<"\n";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}