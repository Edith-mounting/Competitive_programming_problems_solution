#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
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

int32_t main(){
    int N=100001;
    vector<bool> v(N,true);
    v[0]=false;
    v[1]=false;
    for(int i=2;i*i<=N;i++){
        if(v[i]){
            for(int j=i*2;j<N;j+=i){
                v[j]=false;
            }
        }
    }
    vi prime;
    for(int i=0;i<N;i++){
        if(v[i]){
            prime.pb(i);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        vector<bool> isprime(r-l+1,true);
        for(int i=0;(prime[i]*prime[i])<=r;i++){
            int currPrime=prime[i];
            int base=(l/prime[i])*prime[i];
            if(base<l){
                base+=currPrime;
            }
            for(int j=base;j<=r;j+=currPrime){
                isprime[j-l]=false;
            }
            if(base==currPrime){
                isprime[base-l]=true;
            }
        }
        for(int i=0;i<=r-l;i++){
            if(isprime[i]){
                cout<<i+l<<" ";
            }
        }
    }
}