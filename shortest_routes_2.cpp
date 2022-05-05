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
class comp{
    public:
        bool operator()(pair<int,int> x, pair<int,int> y) {
            return x.ss>y.ss;
        }
};
int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v,k;
        cin>>u>>v>>k;
        adj[u].pb({v,k});
        adj[v].pb({u,k});
    }
    int dis[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        vector<bool> vis(n+1,false);
        dis[i][i]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> p;
        p.push({i,0});
        int index;
        int minvalue,newdis;
        while(!p.empty()){
            index=p.top().ff,minvalue=p.top().ss;
            p.pop();
            vis[index]=true;
            if(dis[i][index]<minvalue){
                continue;
            }
            for(int nb=0;nb<adj[index].size();nb++){
                int nbk=adj[index][nb].ff;
                if(vis[nbk]){
                    continue;
                }
                newdis=dis[i][index]+adj[index][nb].ss;
                if(newdis<dis[i][nbk]){
                    dis[i][nbk]=newdis;
                    p.push({nbk,newdis});
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dis[a][b]==inf){
            cout<<-1;
        }
        else{
            cout<<dis[a][b];
        }
        cout<<"\n";
    }
}
