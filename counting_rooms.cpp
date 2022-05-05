#include <iostream>
#include <algorithm>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vector<bool>> adj;
int n,m;
void dfs(int i,int j){
    adj[i][j]=true;
    if(j-1>=0){
        if(!adj[i][j-1]){
            dfs(i,j-1);
        }
    }
    if(i-1>=0){
        if(!adj[i-1][j]){
            dfs(i-1,j);
        }
    }
    if(i+1<n){
        if(!adj[i+1][j]){
            dfs(i+1,j);
        }
    }
    if(j+1<m){
        if(!adj[i][j+1]){
            dfs(i,j+1);
        }
    }
}
int32_t main() 
{
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char k;
            cin>>k;
            if(k=='#'){
                adj[i].pb(true);
            }
            else{
                adj[i].pb(false);
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!adj[i][j]){
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count<<"\n";
}

