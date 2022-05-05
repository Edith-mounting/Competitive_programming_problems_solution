#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue> 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x;
vector<vi> adj;
vi dp;
vector<bool> vis;
void dfs(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j);
        }
    }
    vi k;
    for(int j:adj[i]){
        k.pb(dp[j]);
    }
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    for(int j=0;j<k.size();j++){
        dp[i]=(dp[i]+ (j+1)*k[j]);
    }
    dp[i]=(dp[i]+1);
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        cin>>n>>x;
        dp.clear();
        vis.clear();
        adj.clear();
        vis.resize(n+1,false);
        dp.resize(n+1,0);
        adj.resize(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        cout<<(dp[1]*x)%mod<<"\n";
    }
}