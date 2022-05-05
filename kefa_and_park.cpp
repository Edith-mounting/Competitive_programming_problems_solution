#include<iostream>
#include <vector>
#include <set>
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
vi count;
int k;
void dfs(int cur,int par,int a[],int m){
    if(a[cur]!=0){
        count[cur]=count[par]+1;
    }else{
        if(count[par]>m){
            count[cur]=count[par];
        }
        else{
            count[cur]=0;
        }
    }
    for(int nb:adj[cur]){
        if(nb==par)continue;

        dfs(nb,cur,a,m);
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int a[n+1];
    k=0;
    count.resize(n+1);
    count[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    adj[1].pb(0);
    dfs(1,0,a,m);
    /*for(int i=1;i<n+1;i++){
        cout<<count[i]<<" ";
    }*/
    for(int i=1;i<n+1;i++){
        if(adj[i].size()==1){
            if(count[i]<=m)k++;
        }
    }
    cout<<k<<"\n";
}