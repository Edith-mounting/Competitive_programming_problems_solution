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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vi> adj;
vector<bool> vis;
void dfs(int cur){
    vis[cur]=true;
    for(int nb:adj[cur]){
        if(vis[nb])continue;
        
        dfs(nb);
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vis.resize(n+1,false);
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans.pb(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<"\n";
    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<"\n";
    }
}
