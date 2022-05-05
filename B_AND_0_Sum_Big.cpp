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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y&1){
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (t*t)%mod;
    }
}
int32_t main(){
    int N=100000+10;
    int fact[N]={};
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        cout<<powd(n,k)<<"\n";
    }
}