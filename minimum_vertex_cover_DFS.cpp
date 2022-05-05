#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
using namespace std;
int dp[100001][2];
void minimum_vertex_cover(int cur,int par,vector<int> *adj){
    dp[cur][0]=0;
    dp[cur][1]=1;
    for(int nb:adj[cur]){
        if(nb==par)continue;
        
        minimum_vertex_cover(nb,cur,adj);
        dp[cur][0]+=dp[nb][1];
        dp[cur][1]+=dp[nb][0];  
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
    minimum_vertex_cover(1,0,adj);
    cout<<min(dp[1][0],dp[1][1]);
}