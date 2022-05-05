#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs( int i, vector<vector<int > > &adj, int par,
                        vector<int> &dist, vector<int> &child, int &count){
    count++;
    for(int j:adj[i]){
        if(j == par){
            continue;
        }
        dfs( j, adj, i, dist, child, count);
        child[i] += 1 + child[j];
        dist[i] += count;
    }
    count--;
}
void dfs2( int i, vector<vector<int > > &adj, int par,
                        vector<int> &dist, vector<int> &child, int n){
    for(int j:adj[i]){
        if(j == par)continue;
        dist[j] = dist[i] - 2*child[j] + n - 2;
        dfs2( j, adj, i, dist, child, n);
    }
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int > > adj( n + 1);
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist( n + 1, 0);
    vector<int> child( n + 1, 0);
    int count = 0;
    dfs( 1, adj, -1, dist, child, count);

    for(int i = 2; i <= n; i++){
        dist[1] += dist[i];
    }
    //lets find the solution
    dfs2( 1, adj, -1, dist, child, n);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}
int32_t main(){
    solve();
}
