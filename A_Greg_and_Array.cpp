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
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
struct help{
    int l,r,d;
};
const int maxn=1e5 +5;
int n,m,k;
int t1[4*maxn],t[4*maxn];
void build1(int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build1(v*2, tl, tm);
        build1(v*2+1, tm+1, tr);
        t1[v] = 0;
    }
}

void update1(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t1[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update1(v*2, tl, tm, l, min(r, tm), add);
        update1(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}
int get1(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t1[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t1[v] + get1(v*2, tl, tm, pos);
    else
        return t1[v] + get1(v*2+1, tm+1, tr, pos);
}
void build(int a[], int v, int tl, int tr){
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
int32_t main(){
    FIO;
    cin>>n>>m>>k;
    build1(1,0,m-1);
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    build(a,1,0,n-1);
    vector<help> v(m);
    for(int i=0;i<m;i++){
        help p;
        cin>>p.l>>p.r>>p.d;
        v[i]=p;
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        update1(1,0,m-1,a-1,b-1,1);
    }
    // vi x(m);//ith operation have to be done x[i]th time
    // for(int i=0;i<m;i++){
    //     x[i]=get1(1,0,m-1,i);
    // }
    for(int i=0;i<m;i++){
        int q=get1(1,0,m-1,i);
        if((v[i].d*q)>0){
            update(1,0,n-1,v[i].l-1,v[i].r-1,(v[i].d*q));
        }
    }
    for(int i=0;i<n;i++){
        cout<<get(1,0,n-1,i)<<" ";
    }
    cout<<"\n";
    //watch lazy propagation of segment trees for this problem

}
