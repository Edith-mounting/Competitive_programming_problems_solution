#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
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
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)%mod*x)%mod;
    }
}
// Driver Code
const int N=800000+5;
struct data{
    int sum,pref,suff;
};
data t[N];
data combine(data l,data r){
    data res;
    res.sum=max(l.sum,max(r.sum,l.suff+r.pref));
    if(l.pref==l.sum){
        res.pref=max(l.pref,l.pref+r.sum);
    }
    else{
        res.pref=l.pref;
    }
    if(r.suff==r.sum){
        res.suff=max(r.suff,r.suff+l.sum);
    }
    else{
        res.suff=r.suff;
    }
    return res;
}
data make_data(int val){
    data res;
    res.sum=res.pref=res.suff=val;
    return res;
}
void build(int a[], int v, int tl, int tr){
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
void update(int v, int tl, int tr, int pos, int new_val){
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,1,0,n-1);
    for(int i=1;i<=9;i++){
        cout<<t[i].sum<<" "<<t[i].pref<<" "<<t[i].suff<<"\n";
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        update(1,0,n-1,l-1,r);
        cout<<max((int)0,t[1].sum)<<"\n";
    }
}
