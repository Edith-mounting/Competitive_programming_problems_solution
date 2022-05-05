#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve(){
    int n,m;
    cin>>n>>m;
    int src,dest;
    vector<vector<pii>> adj(n+1);
    int u,v,di;
    for(int i=0;i<m;i++){
        cin>>u>>v>>di;
        adj[u].pb({v,di});
        adj[v].pb({u,di});
    }
    vi dis(n+1,-inf);
    vector<bool> vis(n+1,false);
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        p.ff=-p.ff;
        for(pii i:adj[p.ss]){
            if(!vis[i.ff]){
                if(dis[i.ff]>dis[p.ff]+i.ss){
                    dis[i.ff]=dis[p.ff]+i.ss;
                    pq.push({dis[i.ff],i.ff});
                }
            }
        }
    }
    cout<<dis[dest]<<"\n";
}
int32_t main(){
    FIO;
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
