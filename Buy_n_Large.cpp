#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
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
const int N=1500+5;
vector<vi> adj;
vector<bool> vis;
int c[N+1];
int cost;

void dfs(int i,int &a, vi &ran){
    vis[i]=true;
    ran.push_back(c[i]);
    for(int j:adj[i]){
        if(!vis[j]){
            a = max(a,min(c[i], c[j]));
            dfs(j,a,ran);
        }
    }
}
void f(int i){
    vis[i]=true;
    vi ran;
    if(adj[i].size()==0){
        cost+=c[i];
        return ;
    }
    int a = -1;
    dfs(i,a,ran);
    sort(ran.begin(), ran.end());
    int nl=ran.size();
    for(int i=0;i<=(nl-1)/2;i++){
        cost+=2*ran[i];
    }
    if(nl%2==1){
        cost-=ran[(nl-1)/2];
    }
}
void solve(){
    int n,p;
    cin>>n>>p;
    cost=0;
    c[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>c[i];
    }
    vis.clear();
    vis.resize(n+1,false);
    adj.clear();
    adj.resize(n+1);
    int u,v;
    for(int i=0;i<p;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            f(i);
        }
    }
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
        cout<<cost<<"\n";
    }    
}
