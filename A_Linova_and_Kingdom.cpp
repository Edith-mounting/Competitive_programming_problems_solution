#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
vector<vi> adj;
vector<bool> vis;
vi par;
vi level;
vi child;
priority_queue<pii> pq;
void dfs(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            par[j]=i;
            level[j]=level[i]+1;
            dfs(j);
            child[i]+=(child[j]+1);
        }
    }
    if(child[i]==0){
        pq.push({level[i],i});
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    adj.resize(n+1);
    vis.resize(n+1,false);
    par.resize(n+1,-1);
    level.resize(n+1,0);
    child.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    int ans=0;
    vector<bool> vb(n+1,false);
    for(int i=0;i<k;i++){
        pii x=pq.top();
        // cout<<x.ff<<" "<<x.ss<<"\n";
        pq.pop();
        ans+=x.ff;
        int xl=par[x.ss];
        if(!vb[xl]){
            pq.push({level[xl]-child[xl],xl});
            vb[xl]=true;
        }
    }
    cout<<ans;
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}
}
