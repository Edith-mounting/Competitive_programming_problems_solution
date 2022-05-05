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
bool b=true;
bool dfs(int cur,int par){
    int count=0;
    for(int nb:adj[cur]){
        if(adj[nb].size()==1){
            count++;
        }
        else{
            if(nb==par){
                continue;
            }
            else{
                dfs(nb,cur);
            }
        }
    }
    if(count<3){
        b=false;
    }
}
int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        adj[i].pb(u);
        adj[u].pb(i);
    }
    dfs(1,0);
    if(b){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}