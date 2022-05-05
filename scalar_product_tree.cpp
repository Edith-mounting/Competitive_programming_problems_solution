#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vi> adj;
vi part;
void dfs(int cur,int par){
    for(int nb:adj[cur]){
        if(nb==par){
            continue;
        }
        else{
            dfs(nb,cur);
            part[nb]=cur;
        }
    }
}
int32_t main(){
    int n,q;
    cin>>n>>q;
    int moda=pow(2,32);
    int w[n+1];
    w[0]=0;
    for(int i=1;i<=n;i++){
        int tkl;
        cin>>tkl;
        w[i]=tkl;
    }
    adj.resize(n+1);
    part.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    part[0]=-1;
    part[1]=0;
    dfs(1,0);
    while(q--){
        int a,b,k=0;
        cin>>a>>b;
        while(part[a]!=-1){
            k+=w[a]*w[b];
            k=k%moda;
            a=part[a];
            b=part[b];
        }
        cout<<k<<"\n";
    }
}