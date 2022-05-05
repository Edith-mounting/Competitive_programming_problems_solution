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

vector<vector<pii>> adj;
//here 0-> red
// 1->green
//vector<int> col;
vi bfs(int src,int n,int col){
    queue<int> q;
    q.push(src);
    vi dis(n+1,-1);
    dis[src]=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(pii nb:adj[k]){
            if((dis[nb.ff] !=-1) || (nb.ss !=col)){
                continue;
            }
            else{
                q.push(nb.ff);
                dis[nb.ff]=dis[k]+1;
            }
        }
    }
    return dis;
}
int32_t main(){
    adj.clear();
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v,col;
        cin>>u>>v>>col;
        adj[u].pb({v,col});
        adj[v].pb({u,col});
    }
    int src,dest;
    cin>>src>>dest;
    int ans=inf;
    vi dis1=bfs(src,n,0);
    vi dis2=bfs(dest,n,1);
    for(int i=1;i<=n;i++){
        if(i==src || i==dest || dis1[i]==-1 || dis2[i]==-1 || dis1[dest]==-1){
            continue;
        }
        ans=min(ans,dis1[i]+dis2[i]);
    }
    if(ans==inf){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
}