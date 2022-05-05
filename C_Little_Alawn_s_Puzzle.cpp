#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
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
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)%mod*x)%mod;
    }
}
vector<vi> adj;
int n;
int ans;
vector<bool> vis;
void dfs(int i){
    vis[i]=true;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j);
        }
    }
}
// Function to print answer
void solve()
{
 
    // Setting parent to itself
    cin>>n;
    ans=0;
    int a[2][n];
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }
    for(int i=0;i<n;i++){
        cin>>a[1][i];
    }
    vis.clear();
    vis.resize(n+1,false);
    adj.clear();
    adj.resize(n+1);
    for (int i = 0; i < n; i++) {
        adj[a[0][i]].pb(a[1][i]);
        adj[a[1][i]].pb(a[0][i]);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<powd(2,ans)<<"\n";

}
 
// Driver Code
int32_t main()
{
    int w;
    cin>>w;
    while(w--){
        solve();
    }
}
