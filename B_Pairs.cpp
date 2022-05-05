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
struct coo{
    int x,y;
};
int32_t main(){
    int n,m;
    cin>>n>>m;
    int N=n+1;
    vector<coo> v(m);
    vi v1(N,0);
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        v[i].x=p;
        v[i].y=q;
    }
    //let one value is v[0].x
    bool bl=false;
    int count=0;
    for(int i=0;i<m;i++){
        if(!(v[i].x==v[0].x || v[i].y==v[0].x)){
            count++;
            v1[v[i].x]++;
            v1[v[i].y]++;
        }
    }
    for(int i=1;i<n+1;i++){
        if(v1[i]==count){
            bl=true;
            break;
        }
    }
    if(!bl){
        count=0;
        vi v2(N,0);
        for(int i=0;i<m;i++){
            if(!(v[i].x==v[0].y || v[i].y==v[0].y)){
                count++;
                v2[v[i].x]++;
                v2[v[i].y]++;
            }
        }
        for(int i=1;i<n+1;i++){
            if(v2[i]==count){
                bl=true;
                break;
            }
        }
    }
    if(bl){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}