#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        if(k==0){
            cout<<1;
            return ;
        }
        else{
            cout<<-1;
            return ;
        }
    }
    if(k< n/2){
        cout<<-1;
        return ;
    }
    vi v;
    // int i;
    // for(i=1;i<=n-2- n%2;i++){
    //     v.pb(i);
    // }
    // k=k- (n-2)/2;
    // v.pb(k);
    // v.pb(2*k);
    // for(int i=0;i<v.size();i++){

    // }
    // if(n%2==1){
    //     v.pb(1);
    // }
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    int ans=k- (n-2)/2;
    v.pb(ans);
    ans=ans*2;
    v.pb(ans);
    for(int i=1;i<=n-2;i++){
        v.pb(++ans);
    }
    for(auto i:v){
        cout<<i<<" ";
    }
}
int32_t main(){
    FIO;
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }
}