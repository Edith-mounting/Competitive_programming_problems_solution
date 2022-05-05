#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
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
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
struct help{
    int x,y,weight;
};
bool comp(help x,help y){
    return x.weight<y.weight;
}
const int N=1e5+5;
int sz[N];
int par[N];
int f(int x){
    if(par[x]==x) return x;
    else return par[x]=f(par[x]);
}
void merg(int a,int b){
    int pa=f(a),pb=f(b);
    if(pa==pb) return;
    if(sz[pa]>sz[pb]){
        sz[pa]+=sz[pb];
        par[pb]=pa;
    }else{
        sz[pb]+=sz[pa];
        par[pa]=pb;
    }
    return;
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=a[0];
    for(int i=1;i<n;i++){
        ans=ans&a[i];
    }
    cout<<ans<<"\n";
}
int32_t main(){
    FIO;
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
