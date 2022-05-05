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
int n;
vector<vi> adj;
map<pii,int> mp;
vi degree;
vector<vi> ans;
vector<bool> vis;
vector<vi> nodes;
void bfs(int i1){
    queue<int> q;
    q.push(i1);
    vis[i1]=true;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        int count=1;
        for(int j:adj[i]){
            if(!vis[j]){
                vis[j]=true;
                q.push(j);
                if(nodes[i].size()!=0){
                    if(nodes[i][0]==count){
                        count++;
                    }
                }
                nodes[j].pb(count);
                ans[count].pb(mp[{i,j}]);
                count++;
            }
        }
    }
}
int32_t main()
{
	FIO;
    cin>>n;
    adj.resize(n+1);
    degree.resize(n+1,0);
    nodes.resize(n+1);
    vis.resize(n+1,false);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        mp[{u,v}]=i+1;
        mp[{v,u}]=i+1;
        degree[u]++;
        degree[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int maxi=0,i1=1;
    for(int i=1;i<=n;i++){
        if(degree[i]>maxi){
            maxi=degree[i];
            i1=i;
        }
    }
    ans.resize(maxi+1);
    // cout<<i1<<"\n";
    bfs(i1);
    cout<<maxi<<"\n";
    for(int i=1;i<=maxi;i++){
        cout<<ans[i].size()<<" ";
        for(int j:ans[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
