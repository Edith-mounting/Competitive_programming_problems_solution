#include <iostream>
#include <algorithm>
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
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vi> adj;
vi child;
int ans;
void find(int v,int w){
    if(child[v]!=0){
        if(w%child[v] ==0){
            for(int nb:adj[v]){
                find(nb,w/child[v]);
            }
        }
        else{
            ans+=w;
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    int a[n-1];
    for(int i=1;i<n;i++)cin>>a[i-1];
    child.resize(n+1);
    adj.resize(n+1);
    for(int i=0;i<n+1;i++){
        child[i]=0;
    }
    for(int i=0;i<n-1;i++){
        child[a[i]]++;
    }
    for(int i=1;i<n;i++){
        adj[a[i-1]].pb(i+1);
    }
    int q;
    cin>>q;
    while(q--){
        ans=0;
        int v,w;
        cin>>v>>w;
        find(v,w);
        cout<<ans<<"\n";
    }
}