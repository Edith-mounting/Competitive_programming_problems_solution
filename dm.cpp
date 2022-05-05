#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
using namespace std;
int level[100001]={};
void dfs(int cur,int par,vector<int> *adj){
    level[cur]=level[par]+1;
    for(int nb:adj[cur]){
        if(nb==par)continue;
        
        dfs(nb,cur,adj);  
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> *adj=new vector<int>[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,adj);
    cout<<1<<" ";
    for(int i=2;i<n;i++){
        if(level[i]%2!=0){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    for(int i=2;i<n;i++){
        if(level[i]%2==0){
            cout<<i<<" ";
        }
    }
    cout<<"\n";

}