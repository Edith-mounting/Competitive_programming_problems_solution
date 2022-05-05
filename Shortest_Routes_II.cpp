#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define minusinf        1e-18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int n,ml,q;
    cin>>n>>ml>>q;
    int m[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m[i][j]=inf;
        }
    }
    for(int i=1;i<=ml;i++){
        int u,v,w;
        cin>>u>>v>>w;
        m[u][v]=w;
        m[v][u]=w;
    }
    int dp[n+1][n+1];
    int next[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=m[i][j];
            if(m[i][j]==inf){
                next[i][j]=j;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]+dp[k][j]<dp[i][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]+dp[k][j]<dp[i][j]){
                    dp[i][j]=-1;
                    next[i][j]=-1;
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dp[a][b]==inf || dp[a][b]==-1){
            cout<<-1;
        }
        else{
            cout<<dp[a][b];
        }
        cout<<"\n";
    }
}