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
double dfs(int i){
    vis[i]=true;
    double k=0;
    for(int nb:adj[i]){
        if(!vis[i])k+=dfs(nb)+1;
    }
    if(i==0){
        return k/(adj[i].size());
    }
    else{
        if(adj[i].size()==1){
            return 0;
        }
        else{
            return k/adj[i].size();
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1,false);
    dis.resize(n+1,0);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout<<fixed<<setprecision(7)<<dfs(1)<<"\n";
}