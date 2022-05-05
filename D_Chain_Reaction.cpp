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
int32_t main(){
    int n;
    cin>>n;
    int mini=n;
    vector<pii> v(n);
    int maxia=0;
    for(int i=0;i<n;i++){
        cin>>v[i].ff>>v[i].ss;
        maxia=max(maxia,v[i].ff);
    }
    sort(v.begin(),v.end());
    int N=maxia+1;
    int k=0;
    int dp[N]={};
    for(int i=0;i<N;i++){
        if(i==v[k].ff){
            if(i-v[k].ss-1>=0){
                dp[i]=dp[i-v[k].ss-1]+1;
            }
            else{
                dp[i]=1;
            }
            k++;
        }
        else{
            if(i==0){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[v[i].ff]);
    }
    cout<<n-maxi<<"\n";
}