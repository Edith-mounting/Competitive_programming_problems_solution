#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
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
#define mod             1000007
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
vector<bool> col;
void dfs(int cur,int par){
    if(col[par]==true){
        col[cur]=false;
    }
    else{
        col[cur]=true;
    }
    for(int nb:adj[cur]){
        if(nb==par)continue;

        dfs(nb,cur);
    }
}
int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    col.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    col[1]=true;
    dfs(1,0);
    int red=0,blue=0;
    for(int i=1;i<=n;i++){
        if(col[i]){
            red++;
        }
        else{
            blue++;
        }
    }
    cout<<(red*blue) -n+1<<"\n";
}