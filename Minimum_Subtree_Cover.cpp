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
vector<vi> adj;
vi level;
vector<bool> vis;
int n,k;
vi height;
void dfs1(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            level[j]=level[i]+1;
            dfs1(j);
        }
    }
}
void dfs(int i, vi & ans, int cur){
    vis[i]=true;
    int count=1;
    int maxi = 0;
    for(int j: adj[i]){
        if(!vis[j]){
            count = 0; 
            maxi = max(maxi, height[j]);
        }
    }
    if(count==1){ 
        ans.pb(cur);
        return; 
    }
    int counti = 0;
    for(int j: adj[i]){
        if(vis[j]) continue;

        if(height[j] == maxi && counti==0){
            dfs(j, ans, cur+1);
            counti++;
        }
        else dfs(j, ans, 1);
    }
}

void dfs2(int i){
    int count=1;
    vis[i]=true;
    for(int j: adj[i]){
        if(vis[j]) continue;
        
        count = 0;
        dfs2(j);
        height[i] = max(height[i], 1 + height[j]);
    }
    if(count==1)height[i] = 1;
}

int solve(){
    cin>>n>>k;
    level.clear();
    level.resize(n+1,0);
    vis.clear();
    vis.resize(n+1,false);
    adj.clear();
    adj.resize(n+1);
    height.clear();
    height.resize(n+1,0);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    dfs1(1);
    int ul=1;
    int ds=0;
    for(int i=1;i<n+1;i++){
        if(level[i]>ds){
            ds=level[i];
            ul=i;
        }
    }
    if(k==1) return 1;
    vi ans;
    vis.clear();
    vis.resize(n+1,false);
    int nod=ul,par=0;
    dfs2(nod);
    vis.clear();
    vis.resize(n+1,false);
    dfs(nod,ans, 1);
    sort(ans.rbegin(), ans.rend());
    int size = 1, total = 0, i = 0;
    while(total < k){
        size++;
        total += ans[i++];
    }
    return size;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int w=1;
    cin>>w;
    while(w--){
        cout<<solve()<<"\n";
    }
}