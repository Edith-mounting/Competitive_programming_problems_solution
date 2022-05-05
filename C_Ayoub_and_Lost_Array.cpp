#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
 
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
int32_t main(){
    FIO;
    int n,l,r;
    cin>>n>>l>>r;
    int a[3];
    a[0]=(r-l+1)/3;
    a[1]=(r-l+1)/3;
    a[2]=(r-l+1)/3;
    int q=(r-l+1)%3;
    if(q==2){
        a[l%3]++;
        a[(l+1)%3]++;
    }
    else if(q==1){
        a[l%3]++;
    }
    // for(int i=0;i<3;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    vector<vi> dp(n,vi(3,0));
    dp[0][0]=a[0];
    dp[0][1]=a[1];
    dp[0][2]=a[2];
    for(int i=1;i<n;i++){
        dp[i][0]=(dp[i-1][0]*a[0])%mod +(dp[i-1][1]*a[2])%mod+(dp[i-1][2]*a[1])%mod;
        dp[i][1]=(dp[i-1][1]*a[0])%mod +(dp[i-1][2]*a[2])%mod+(dp[i-1][0]*a[1])%mod;
        dp[i][2]=(dp[i-1][2]*a[0])%mod +(dp[i-1][0]*a[2])%mod+(dp[i-1][1]*a[1])%mod;
        dp[i][0]%=mod,dp[i][1]%=mod,dp[i][2]%=mod;
    }   
    cout<<(dp[n-1][0]%mod)<<"\n";
}