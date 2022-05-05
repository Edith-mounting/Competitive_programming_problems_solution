#include <bits/stdc++.h>
using namespace std;

void CalDist(int i, vector<vector<int>> &adj, int par, vector<int> &dist){
    for(int j:adj[i]){
        if(j == par)continue;
        dist[j] = max(1 + dist[i], dist[j]);
        CalDist( j, adj, i, dist);
    }
}
pair< int, int> dfs(int i, vector<vector<int>> &adj, int par){
    int maxi = 0, node = i;
    pair< int, int> temp;
    for(int j:adj[i]){
        if(j == par){
            continue;
        }
        temp = dfs( j, adj, i);
        maxi = max( maxi, temp.first + 1);
        if(maxi == temp.first + 1){
            node = temp.second;
        }
    }
    return { maxi, node};
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
    vector<int> dist(n + 1, 0), dist2(n + 1, 0);
    pair<int , int> x = dfs( 1, adj, -1);
    pair<int , int> y = dfs( x.second, adj, -1);
    CalDist( x.second, adj, -1, dist);
    CalDist( y.second, adj, -1, dist2);
    for(int i = 1; i <= n; i++){
        int ans = max(dist[i], dist2[i]);
        cout << ans << " ";
    }
    cout << "\n";
}
int32_t main(){

    solve();
}
