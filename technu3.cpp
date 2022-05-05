#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
int N=200000;
vi fac;
int power(int x, int y, int p)
{
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=(power(x,y/2,p)%mod);
        return (t*t)%mod;
    }
    else{
        int t=(power(x,y/2,p)%mod);
        return (((t*t)%mod)*x)%mod;
    }
}
 
int modInverse(int n,int p)
{
    return power(n, p - 2, p);
}
int nCrModPFermat(int n, int r,int p)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;
    
    return (((fac[n]*modInverse(fac[n-r],p))%p)*modInverse(fac[r],p))%p;
}
int32_t main(){
    int a[2][2]={1,2,4,32};
    cout<<a[0][0]<<" ";
}