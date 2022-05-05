#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <queue>
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    if(n<4){
        ans = ans/n;
        cout<<ans<<"\n";
        return;
    }
    int k = n - 4;
    int fact[k+1];
    fact[0] = 0;
    for(int i=1;i<=k;i++){
        if(fact[i-1] >= 100000000000){
            fact[i] = inf;
        }
        else{
            fact[i] = i*fact[i-1];
        }
    }
    if(fact[k] >= ans){
        ans = 0;
    }
    else{
        ans = ans/(2*fact[k]);
    }
    cout<<ans<<"\n";
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}