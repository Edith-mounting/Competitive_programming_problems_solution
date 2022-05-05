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
#define int             long long
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
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
vector<vector<pii>> adj;
vector<bool> vis;
class comp{
    public:
        bool operator()(pair<int,int> x, pair<int,int> y) {
            return x.ss>y.ss;
        }
};
int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,false);
    for(int i=1;i<=m;i++){
        int u,v,k;
        cin>>u>>v>>k;
        adj[u].pb({v,k});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> p;
    vi dis(n+1,inf);
    dis[1]=0;
    p.push({1,0});
    int index;
    int minvalue,newdis;
    while(!p.empty()){
        index=p.top().ff,minvalue=p.top().ss;
        p.pop();
        vis[index]=true;
        if(dis[index]<minvalue){
            continue;
        }
        for(int nb=0;nb<adj[index].size();nb++){
            int nbk=adj[index][nb].ff;
            if(vis[nbk]){
                continue;
            }
            newdis=dis[index]+adj[index][nb].ss;
            if(newdis<dis[nbk]){
                dis[nbk]=newdis;
                p.push({nbk,newdis});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
