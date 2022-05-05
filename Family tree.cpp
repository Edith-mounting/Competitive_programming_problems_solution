#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
using namespace std;
int a[100001];
int ans=0;
pair<int,int> dfs(int root,int par,vector<vector<int>> &adj){
    int min_dif=a[root];
    int max_dif=a[root];
    for(int nb:adj[root]){
        if(nb==par)continue;
        
        pair<int,int> pii=dfs(root,par,adj);
        min_dif=min(min_dif,pii.first);
        max_dif=max(max_dif,pii.second);
    }
    ans=max(ans,a[root]-min_dif);
    ans=max(ans,max_dif-a[root]);
    return {min_dif,max_dif};
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int root;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k==-1){
            root=i;
        }
        else{
            adj[k].push_back(i);
            adj[i].push_back(k);
        }
    }
    pair<int,int> pil=dfs(root,-1,adj);
    cout<<ans<<"\n";
}