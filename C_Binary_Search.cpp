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
vi fac;
int power(int x,int y, int p)
{
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=power(x,y/2,p)%p;
        return (t*t)%p;
    }
    else{
        int t=power(x,y/2,p)%p;
        return ((t*t)%p*(x))%p;
    }
}
 
int modInverse(int n,int p)
{
    return power(n, p - 2, p);
}
int nPrModPFermat(int n,int r, int p)
{   
    if(n < r)return 0;
    if(r == 0)return 1;
    return ((fac[n]%p)*(modInverse(fac[n - r], p) % p))% p;
}
int32_t main(){
    int n,x,pos,large=0,small=0;
    cin>>n>>x>>pos;
    int l=0,r=n;
    int mid;
    fac.resize(1001);
    fac[0]=1;
    for(int i=1;i<1001;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
    while(l<r){
        mid=(l+r)/2;
        if(mid<=pos){
            if(mid!=pos){
                small++;
            }
            l=mid+1;
        }
        else{
            large++;
            r=mid;
        }
    }
    cout<<((fac[n-1-large-small])%mod)*((nPrModPFermat(n-x,large,mod)*nPrModPFermat(x-1,small,mod))%mod)%mod;
    cout<<"\n";
}