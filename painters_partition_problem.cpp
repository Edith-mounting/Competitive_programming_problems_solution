#include <iostream>
#include <algorithm>
#include <map>
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vi> dp(n+1,vi(k+1,0));
    vi sum(n,0);
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<sum[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=1;i<=n;i++){
        dp[i][1]=sum[i-1];
    }
    for(int i=1;i<=k;i++){
        dp[1][i]=a[0];
    }
    for(int j=2;j<=k;j++){
        for(int i=2;i<=n;i++){
            if(i==n && j==1){
                continue;
            }
            if(i==1 && j==k){
                continue;
            }
            int q=inf;
            for(int p=1;p<=n;p++){
                q=min(q,max(dp[p][j-1],sum[p+1]));
            }
            dp[i][j]=q;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][k]<<"\n";
}