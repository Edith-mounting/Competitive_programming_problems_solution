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
    vi v1,v2;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v1.pb(i);
            if(i != n/i){
                v2.pb(n/i);
            }
        }
    }
    if(v1.size()+v2.size()<k){
        cout<<-1;
        return ;
    }
    reverse(v2.begin(),v2.end());
    if(v1.size()>=k){
        cout<<v1[k-1];
    }
    else{
        k=k-v1.size();
        cout<<v2[k-1];
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