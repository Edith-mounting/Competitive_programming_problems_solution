#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
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
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}

int32_t main(){
    int N=200000 +10;
    int fact[N];
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int x=a[0];
        for(int i=1;i<n;i++){
            x=x&a[i];
        } 
        int k=0;
        for(int i=0;i<n;i++){
            if(a[i]==x)k++;
        }
        //cout<<k<<' ';
        int ans=0;
        if(k>=2){
        ans=(((k*(k-1))%mod)*fact[n-2])%mod;}
        cout<<ans<<"\n";
    }
}