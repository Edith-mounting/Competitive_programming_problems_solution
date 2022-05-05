#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
int n,k;
vector<bool> vis;
vector<vi> adj;
int bfs(int i){
    vis[i]=true;
    int count=0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int child=q.front();
        q.pop();
        count++;
        for(int j:adj[child]){
            if(!vis[j]){
                q.push(j);
                vis[j]=true;
            }
        }
    }
    return count;
}
int32_t main()
{
	FIO;
    cin>>n>>k;
    adj.resize(n+1);
    vis.resize(n+1,false);
    for(int i=0;i<n-1;i++){
        int u,v,x;
        cin>>u>>v>>x;
        if(x==0){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    int ans1=powd(n,k);
    int ans2=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int q=bfs(i);
            ans2=(ans2+ powd(q,k))%mod;
        }
    }
    int ans=(ans1-ans2+mod)%mod;
    cout<<ans<<"\n";
}