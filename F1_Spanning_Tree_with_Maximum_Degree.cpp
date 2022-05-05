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
void bfs(int i){
    vis[i]=true;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int nb=q.front();
        q.pop();
        for(int j:adj[nb]){
            if(!vis[j]){
                cout<<nb<<" "<<j<<"\n";
                vis[j]=true;
                q.push(j);
            }
        }
    }
}
int32_t main()
{
	FIO;
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,false);
    vi order(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        order[a]++;
        order[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int maxi=0,i1=-1;
    for(int i=1;i<=n;i++){
        if(order[i]>maxi){
            maxi=order[i];
            i1=i;
        }
    }
    bfs(i1);
}