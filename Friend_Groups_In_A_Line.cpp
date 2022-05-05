#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
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
const int N=1e5 +5;
int par[N],sz[N];
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
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++){
        par[i]=i,sz[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            if(par[i]==i){
                for(int j=i;j<=min((int)(i+k+1),n);j++){
                    if(a[j]==1){
                        merg(i,j);
                    }
                }
            }
        }
        
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if((a[i]==1) && (par[i]==i)){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
