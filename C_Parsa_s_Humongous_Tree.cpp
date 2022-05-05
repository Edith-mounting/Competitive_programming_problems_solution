#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int n;
int limit[100005][2];
int pre[100005][2];
vector<vi> adj;
int dfs(int i,int value,int par){
    if(pre[i][value]!=-1){
        return pre[i][value];
    }
    int counti=0;
    int x=limit[i][value];
    for(int j:adj[i]){
        if(j==par)continue;

        counti+=max(dfs(j,0,i)+absk(x-limit[j][0]),dfs(j,1,i)+absk(x-limit[j][1]));

    }
    pre[i][value]=counti;
    return counti;
}
void solve(){
    cin>>n;
    adj.clear();
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>limit[i][0]>>limit[i][1];
        pre[i][0]=-1;
        pre[i][1]=-1;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans1=dfs(1,0,-1);
    int ans2=dfs(1,1,-1);
    cout<<max(ans1,ans2)<<"\n";
}
int32_t main(){
    FIO;
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }
}