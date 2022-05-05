#include <iostream>
#include <algorithm>
#include <vector>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vi> adj;
vi get_path(int cur,int dest,int n){
    vi dis(n+1,-1);
    vi par(n+1,-1);
    queue<int> q;
    q.push(cur);
    dis[cur]=0;
    par[cur]=0;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int nb:adj[i]){
            if(dis[nb]!=-1){
                continue;
            }
            q.push(nb);
            dis[nb]=dis[i]+1;
            par[nb]=i;
        }
    }
    if(dis[dest]==-1){
        return {};
    }
    vi ans;
    while(par[dest]!=0){
        ans.push_back(dest);
        dest=par[dest];
    }
    ans.push_back(dest);
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin>>a>>b;
    vi ans=get_path(a,b,n);
    for(int i:ans){
        cout<<i<<" ";
    }
}