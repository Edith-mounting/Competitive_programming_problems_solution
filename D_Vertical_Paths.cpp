#include <bits/stdc++.h>
using namespace std;

#define mod             1000000007

//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void dfs(int root, vector< vector< int>> &adj,
                vector<vector<int>> &ans, vector<int> &temp){
    temp.push_back(root);
    for(int i = 0; i < adj[root].size(); i++){
        dfs( adj[root][i], adj, ans, temp);
        if(temp.size() > 0){
            ans.push_back(temp);
            temp.clear();
        }
    
    }
}
int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}
void solve(){
    int n;
    cin >> n;
    vector< vector< int>> adj(n + 1);
    vector<int> fact(n + 1, 0);
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i]*i)%mod;
    }
    int gcd1;
    for(int i = 1; i <= n; i++){
        gcd1 = gcd(i, i + 1);
    }
    int p;
    int root;
    for(int i = 1; i <= n; i++){
        cin >> p;
        if(p == i){
            root = i;
            continue;
        }
        adj[p].push_back(i);
    }
    if(n == 1){
        cout << 1 << "\n";
        cout << 1 <<"\n";
        cout << 1 << "\n";
        cout << "\n";
        return ;
    }
    vector<vector<int>> ans;
    vector<int> temp;
    dfs( root, adj, ans, temp);
    cout << ans.size() << "\n";
    for(auto i:ans){
        cout << i.size() << "\n";
        for(int j:i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)
        solve();    
}