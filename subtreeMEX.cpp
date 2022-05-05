#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
vi sz;
int count1;
void dfs2(int cur,int par){
    count1+=sz[cur];
    bool b=false;
    int k1=0,k2=0,k3=0;
    for(int nb:adj[cur]){
        if(nb==par)continue;

        //int k1=0,k2=0,k3=0;
        if(sz[nb]>k1){
            k1=sz[nb];
            k2=nb;
            k3=cur;
            b=true;
        }
    }
    if(b){
        dfs2(k2,k3);
    }
}
void dfs1(int cur,int par){
    for(int nb:adj[cur]){
        if(nb==par)continue;

        dfs1(nb,cur);
        sz[cur]+=sz[nb];
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        adj.clear();
        sz.clear();
        count1=0;
        adj.resize(n+1);
        sz.resize(n+1);
        adj[1].push_back(0);
        for(int i=1;i<=n-1;i++){
            int k;
            cin>>k;
            adj[i+1].push_back(k);
            adj[k].push_back(i+1);
        }
        for(int i=1;i<n+1;i++){
            sz[i]=1;
        }
        dfs1(1,0);
        dfs2(1,0);
        cout<<count1<<"\n";
    }
}