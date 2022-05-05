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
int n,m;
vector<bool> vis;
vector<vi> adj;
vi temp;
bool bl=true;
void dfs(int i){
    temp.pb(i);
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j);
        }
    }
}
void solve(){
    cin>>n>>m;
    vis.resize(n+1,false);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            temp.clear();
            dfs(i);
            int x1=temp.size();
            int x2=0;
            for(int j:temp){
                x2+=adj[j].size();
            }
            x2/=2;
            if((x1*(x1-1))/2 !=x2){
                bl=false;
            }
        }
    }
    if(bl){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }    
}
