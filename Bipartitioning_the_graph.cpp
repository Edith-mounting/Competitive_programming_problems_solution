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
vector<int> col;
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
bool dfs(int cur){
    queue<int> q;
    q.push(cur);
    col[cur]=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int nb:adj[k]){
            if(col[nb]==-1){
                col[nb]=1-col[k];
                q.push(nb);
            }
            else{
                if(col[nb]==col[k]){
                    return false;
                }
            }
        }
    }
    return true;
}
int number_of_ways(int n){
    int c=0;
    for(int i=1;i<=n;i++){
        if(col[i]!=-1){
            continue;
        }
        bool b=dfs(i);
        c++;
        if(!b){
            return 0;
        }
    }
    return powd(2,c);
}
int32_t main(){
    adj.clear();
    col.clear();
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    col.resize(n+1,-1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k=number_of_ways(n);
    cout<<k;
}