#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void bfs(int root,vector<vector<int>> &adj,int n){
    vector<int> par(n+1);
    par[1]=0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int nb:adj[cur]){
            if(nb!=par[cur]){
                q.push(nb);
                par[nb]=cur;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,adj,n);
}