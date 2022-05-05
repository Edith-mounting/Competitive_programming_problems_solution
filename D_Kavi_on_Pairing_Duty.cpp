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
#define mod             998244353
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
int N=1e6 +5;
void solve(){
    vi prime(N,0);
    for(int i=1;i<N;i++){
        prime[i]=i;
    }
    for(int i=2;i<N;i++){
        if(prime[i]==i){
            for(int j=i*i;j<N;j+=i){
                prime[j]=i;
            }
        }
    }
    int dp[N]={};
    dp[1]=1;
    for(int i=2;i<N;i++){
        int k=i;
        map<int,int> mp;
        while(k>1){
            mp[prime[k]]++;
            k/=prime[k];
        }
        int ans=1;
        for(auto i:mp){
            ans=(ans*(i.ss+1))%mod;
        }
        dp[i]=(ans)%mod;
    }
    int n;
    cin>>n;
    int ans=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i]+sum)%mod;
        sum=(sum +dp[i])%mod;   
    }
    cout<<dp[n];
}
int32_t main(){
    FIO;
    solve();
}