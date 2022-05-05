#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int bfs_closest_leave(int root,vector<vector<int>> &adj,int n){
    vector<int> par(n+1);
    par[1]=0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        //cout<<cur<<" ";
        int k=0;
        for(int nb:adj[cur]){
            if(nb!=par[cur]){
                q.push(nb);
                k++;
                par[nb]=cur;
            }
        }
        if(k==0){
            return cur;
        }
    }
    return 0;
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
    cout<<bfs_closest_leave(1,adj,n);
}