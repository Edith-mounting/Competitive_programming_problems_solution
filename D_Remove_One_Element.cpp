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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int r[n];
    r[n-1]=1;
    for(int i=n-2;i>=0;i--){
        r[i]=1;
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
    }
    int l[n];
    l[0]=1;
    int ans=1;
    for(int i=1;i<n;i++){
        l[i]=1;
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        ans=max(ans,l[i]);
    }
    for(int i=2;i<n;i++){
        if(a[i]>a[i-2]){
            ans=max(ans,l[i-2]+r[i]);
        }
    }
    cout<<ans<<"\n";
}