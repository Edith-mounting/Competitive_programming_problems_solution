#include <iostream>
#include <iomanip>
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
#define pqs             priority_queue<int,vi,greater<int> >//for min-heap in cpp
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
vi part;
void dfs(int cur,int par){
    part[cur]=par;
    for(int nb:adj[cur]){
        if(nb==par)continue;

        dfs(nb,cur);
    }
}
int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    part.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>u;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi leave;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            leave.pb(i);
        }
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<leave.size();i++){
        int m=leave[i];
        while(part[m]!=0){
            ans+=1;
            m=part[m];
        }
    }
    cout<<setprecision(15)<<(ans/(leave.size()));
}