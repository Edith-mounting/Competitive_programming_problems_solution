#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
void bfs(int cur,int n){
    queue<int> q;
    vector<bool> v(n+1,false);
    q.push(cur);
    while(!q.empty()){
        int k=q.front();
        q.pop();
        cout<<k<<" ";
        for(int nb:adj[k]){
            if(v[nb]){
                continue;
            }
            else{
                q.push(nb);
            }
        }
        v[k]=true;
    }
}
int main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,n);
}