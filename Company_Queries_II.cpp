#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> par;
vector<vector< int> > adj;
vector<vector< int> > lift;
void dfs(int v, int par){
    lift[v][0] = par;
    for( int i = 1; i < 30; i++){
        lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }
    for(int u:adj[v]){
        if(u == par)continue;
        dfs( u, v);
    }
}
void solve(){
    int n,q;
    cin >> n >> q;
    par.resize(n + 1);
    adj.resize(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> par[i];
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }
    lift.assign( n + 1, vector<int>( 32, 0));
    dfs( 1, 0);
    int x, y;
    while(q--){
        cin >> x >> y;
        
    }
}
int32_t main(){
    solve();
}
