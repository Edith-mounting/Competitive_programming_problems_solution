#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue> 
#include <iomanip>
using namespace std;

const int PI=3.14159265358;
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
#define mod             1000000009
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
int modinverse(int x){
    return powd(x,mod-2)%mod;
}
int mod2(int x,int i){
    return powd(x,i*(mod-2))%mod;
}
int32_t main(){
    FIO;
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    int x[k];
    for(int i=0;i<k;i++){
        char c;
        cin>>c;
        if(c=='+'){
            x[i]=1;
        }
        else{
            x[i]=-1;
        }
    }
    int ans=(powd(b,n+1)-powd(a,n+1)+mod)%mod;
    ans=(ans*modinverse(b-a))%mod;
    int count=0;
    for(int i=0;i<k;i++){
        count=(count+mod + x[i]*(powd(b,i)*mod2(a,i)))%mod;
    }
    ans=(ans*count + mod)%mod;
    cout<<ans<<"\n";
}