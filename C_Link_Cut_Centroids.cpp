#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
vector<bool> vis;
vi dp;
vector<vi> adj;
vi c;
int n;
void dfs(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j);
            dp[i]+=dp[j];
        }
    }
}

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        cin>>n;
        dp.clear();
        vis.clear();
        adj.clear();
        dp.resize(n+1,1);
        vis.resize(n+1,false);
        adj.resize(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);

        c.clear();
        c.resize(n+1,0);
        vis.clear();
        vis.resize(n+1,false);

        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            c[i]=(n-dp[i]);
            for(int j:adj[i]){
                if(!vis[j]){
                    vis[j]=true;
                    q.push(j);
                    c[i]=max(c[i],dp[j]);
                }
            }
        }
        int mini=inf;
        for(int i=1;i<=n;i++){
            mini=min(mini,c[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<c[i]<<" ";
        // }
        // cout<<"\n";
        vector<int> vl;//for storing who have minimum connected components
        for(int i=1;i<=n;i++){
            if(c[i]==mini){
                vl.pb(i);
            }
        }
        
        if(vl.size()>1){
            int x=vl[1];
            for(int i:adj[vl[0]]){
                if(i!=x){
                    x=i;
                    break;
                }
            }
            cout<<vl[0]<<" "<<x<<"\n";
            cout<<x<<" "<<vl[1]<<"\n";
        }
        else{
            cout<<vl[0]<<" "<<adj[vl[0]][0]<<"\n";
            cout<<vl[0]<<" "<<adj[vl[0]][0]<<"\n";
        }
    }
}