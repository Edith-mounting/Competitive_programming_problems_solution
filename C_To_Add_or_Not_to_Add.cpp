#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue> 
#include <iomanip>
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
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int n,k;
    cin>>n>>k;
    vi a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    vi sum(n+1,0);
    for(int i=1;i<n+1;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int val=a[1],len=1;
    for(int i=2;i<n+1;i++){
        int lo=1,hi=i-1,pos=i;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cost=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
            if(cost<=k){
                pos=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(i-pos+1>len){
            len=i-pos+1;
            val=a[i];
        }
    }
    cout<<len<<" "<<val<<"\n";
}