#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
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
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return powd(x,y/2)*powd(x,y/2);
    }
    else{
        int t=powd(x,y/2);
        return (x*t*t);
    }
}
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int find_set(int v,int par[]) {
    if (v == par[v])
        return v;
    return find_set(par[v],par);
}

void union_sets(int a, int b,int par[],int *sz) {
    a = find_set(a,par);
    b = find_set(b,par);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    int r[n],c[n];
    for(int i=0;i<n;i++)cin>>r[i];
    for(int i=0;i<n;i++)cin>>c[i];
    int par1[n+1];
    int par2[n+1];
    int sz1[n+1];
    int sz2[n+1];
    for(int i=0;i<n+1;i++){
        par1[i]=i;
        par2[i]=i;
        sz1[i]=1;
        sz2[i]=1;
    }

    for(int i=1;i<n;i++){
        if(r[i]%2 == r[i-1]%2){
            //cout<<i<<" ";
            union_sets(i+1,i,par1,sz1);
        }
        if(c[i]%2 == c[i-1]%2){
            union_sets(i+1,i,par2,sz2);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<par1[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=0;i<q;i++){
        int ra,ca,rb,cb;
        cin>>ra>>ca>>rb>>cb;
        if((find_set(ra,par1) == find_set(rb,par1)) && (find_set(ca,par2)==find_set(cb,par2))){
            cout<<"YES";
        }
        else{
            //cout<<par1[ra]<<" "<<par1[rb]<<"\n";
            cout<<"NO";
        }
        cout<<"\n";
    }
}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }
}