#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vi> adj;
vector<bool> vis;
set<int> ans;
vector<int> disc;
vector<int> ance;
int t=0;
void dfs(int i,int par){
    vis[i]=true;
    disc[i]=t;
    ance[i]=t;
    t++;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j,i);
            ance[i]=min(ance[i],ance[j]);
            if(ance[j]>=disc[i]){
                ans.insert(i);
            }
        }
        else{
            if(j!= i){
                ance[i]=min(ance[i],disc[j]);
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n,false);
    ans.clear();
    disc.resize(n,0);
    ance.resize(n,0);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root=0;
    int child=0;
    vis[root]=true;
    disc[root]=1;
    ance[root]=1;
    t++;
    for(int i:adj[root]){
        if(!vis[i]){
            dfs(i,root);
            child++;
        }
    }
    if(child>1){
        ans.insert(root);
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }    
}
