#include <iostream>
#include <algorithm>
#include <map>
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
vector<vi> adj;
vector<bool> vis;
void dfs(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j);
        }
    }
}
int dfs1(int i){
    vis[i]=true;
    int count=1;
    for(int j:adj[i]){
        if(!vis[j]){
            count+=dfs1(j);
        }
    }
    return count;
}
int32_t main(){
    int n,m,s;
    cin>>n>>m>>s;
    adj.resize(n+1);
    vis.resize(n+1,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    dfs(s);
    vector<pii> cnt(n+1);
    for(int i=0;i<n+1;i++){
        cnt[i].ff=0;
        cnt[i].ss=i;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt[i].ff=dfs1(i);
            cnt[i].ss=i;
        }
    }
    int ans=0;
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    for(int i=0;i<n+1;i++){
        cout<<cnt[i].ff<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n+1;i++){
        if(!vis[cnt[i].ss]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<"\n";
}