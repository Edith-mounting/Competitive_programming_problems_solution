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
const int N=1000+5;
int f(int x,vi& par){
    if(par[x]==x) return x;
    else return par[x]=f(par[x],par);
}
void merg(int a,int b,vi& par,vi& sz){
    int pa=f(a,par),pb=f(b,par);
    if(pa==pb)return ;

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
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vi par2(n+1),sz2(n+1,1);
    vi par1(n+1),sz1(n+1,1);
    for(int i=1;i<=n;i++){
        par1[i]=i;
        par2[i]=i;
    }
    int u,v;
    for(int i=0;i<m1;i++){
        cin>>u>>v;
        merg(u,v,par1,sz1);
    }
    for(int i=0;i<m2;i++){
        cin>>u>>v;
        merg(u,v,par2,sz2);
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f(i,par1)!=f(j,par1) && f(i,par2)!=f(j,par2)){
                ans.pb({i,j});
                merg(i,j,par1,sz1);
                merg(i,j,par2,sz2);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }

}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        solve();
        cout<<"\n";
    }    
}
