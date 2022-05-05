#include <iostream>
#include <algorithm>
#include <map>
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    vector<vector<pii>> adj(n);
    int u,v,weight;
    for(int i=0;i<m;i++){
        cin>>u>>v>>weight;
        adj[u].pb({v,weight});
        adj[v].pb({u,weight});
    }
    vector<bool> inMST(n,false);
    vi key(n,inf);
    vi parent(n,-1);
    int src=0;
    pq.push({0,src});
    key[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(inMST[u]){
            continue;
        }
        inMST[u]=true;
        for(pii j:adj[u]){
            int v=j.ff;
            int weight=j.ss;
            if((inMST[v]==false) && key[v]>weight){
                key[v]=weight;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" "<<i<<"\n";
    }   
}