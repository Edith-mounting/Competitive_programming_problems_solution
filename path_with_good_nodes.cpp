#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs( int i,int par, vector<vector<int>> &adj, vector<int> &a, int c, int &ans, int &cur){
    if( a[i - 1] == 1){
        cur++;
    }
    for(int j:adj[i]){
        if(j != par){
            dfs( j, i, adj, a, c, ans, cur);
        }
    }
    if( adj[i].size() == 1 && cur <= c){
        // cout << cur << " ";
        ans++;
    }
    if(a[i - 1] == 1)cur--;
}
int solve(vector<int> &a, vector<vector<int> > &b, int c) {
    int n = a.size();
    vector<vector<int>> adj( n + 1);
    for(auto i:b){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int ans = 0, cur = 0;
    dfs( 1, -1, adj, a, c, ans, cur);
    return ans;
}

int32_t main(){
    int n,c;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector< vector< int>> b(n - 1, vector<int>(2, 0));
    for(int i = 0; i < n - 1; i++){
        cin >> b[i][0] >> b[i][1];
    }
    cin >> c;
    cout << solve( a, b, c) <<"\n";
}