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
void swap(int &x,int &y){
    int k=x;
    x=y;
    y=k;
}
int32_t main() {
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        vi k;
        int l=a[i];
        while(l>0){
            k.pb(l%10);
            l/=10;
        }
        int t=1;
        for(int j=0;j<k.size();j++){
            ans=(ans+(k[j]*((int)11)*t)%mod)%mod;
            t=(t*100)%mod;   
        }
    }
    ans=(ans*n)%mod;
    cout<<ans<<"\n";
}