#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}
vector<vi> adj;
int32_t main(){
    int n,m;
    cin>>n>>m;
    vi c(n+1);
    for(int i=1;i<n+1;i++){
        cin>>c[i];
    }
    map<int,vi> v;
    for(int i=1;i<n+1;i++){
        v[c[i]].pb(i);
    }
    int maxi=0,col;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(c[a]!=c[b]){
            adj[a].pb(c[b]);
            adj[b].pb(c[a]);
        }
    }
    for(auto i:v){
        int x=0;
        for(auto j:i.ss){
            x+=adj[j].size();
        }
        if(maxi<x){
            maxi=x;
            col=i.ff;
        }
        if(maxi==x){
            col=min(col,i.ff);
        }
    }
    cout<<col<<"\n";
}