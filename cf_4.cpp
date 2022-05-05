#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
void solve(){
    int n , k;
    cin >> n >> k;
    vector<vector<int > > adj(n + 1);
    int u , v;
    vector<int> degree(n+1, 0);
    for(int i = 1 ;i<=n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if(k >= n-1){
        cout<<0<<"\n";
        return ;
    }
    queue<int> q;
    vector<bool> vis(n+1,false);
    for(int i =1;i<=n;i++){
        if(degree[i] == 1){
            q.push(i);
            vis[i] = true;
        }
    }
    int ans ;
    while(k--){
        int len = q.size();
        if(len == 0){
            ans = 0;
            break;
        }
        while(len--){
            int top = q.front();
            q.pop();
            for(int j:adj[top]){
                if(!vis[j]){
                    degree[j]--;
                    if(degree[j] == 1 && !vis[j]){
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
        }
    }
    ans = q.size();
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>> t;
    while(t--){
        solve();    
    }
}