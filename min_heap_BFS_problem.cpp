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

int32_t main(){
    FIO;
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pqs q;
    q.push(1);
    vector<bool> vis(n+1,false);
    vis[1]=true;
    vi ans;
    while(!q.empty()){
        int k=q.top();
        ans.pb(k);
        q.pop();
        for(int nb:adj[k]){
            if(vis[nb]){
                continue;
            }
            q.push(nb);
            vis[nb]=true;
        }
    }
    for(int i:ans){
        cout<<i<<" ";
    }

}