#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
 
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t);
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}


// int32_t main(){
//     FIO;
//     int l,x;
//     cin>>l>>x;
//     int k=l/x;
//     int ans=0;
//     from sqrt(k)+1 to k
    
//     if((int)sqrt(k) ==1){
//         ans+=k;
//     }
//     else{
//         int q=(k -(int)sqrt(k));
//         ans+=(q*(q+1))/2;
//         ans+=k;
//     }
//     for(int i=2;i<= (int)sqrt(k);i++){
//         ans+= (k-i)- k/(i);
//     }
//     cout<<ans<<"\n";
// }
int f(int x){
    int q=(12*x +8)%mod;
    q=(q*powd((int)9,mod-2))%mod;
    q=(q*powd(powd(2,x),mod-2))%mod;
    return q;
}
int32_t main(){
    int a,b;
    cin>>a>>b;
    if(a==0 || b==0){
        cout<<0;
    }
    else if(a==1 && b==1){
        cout<<1;
    }
    else{
        int ans=(f(a)+f(b))%mod;
        cout<<ans;
    }
}