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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
int n,q;
const int N=1e5+5;
int a[N];
int t1[4*N],t2[4*N],t3[4*N];
void build1(int v, int tl, int tr,int *t) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build1( v*2, tl, tm,t);
        build1(v*2+1, tm+1, tr,t);
        t[v] = 0;
    }
}
void update1(int v, int tl, int tr, int l, int r, int add,int *t) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update1(v*2, tl, tm, l, min(r, tm), add, t);
        update1(v*2+1, tm+1, tr, max(l, tm+1), r, add, t);
    }
}
int get1(int v, int tl, int tr, int pos,int *t) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get1(v*2, tl, tm, pos,t);
    else
        return t[v] + get1(v*2+1, tm+1, tr, pos,t);
}
int32_t main()
{
	FIO;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build1(1,1,n,t1);
    build1(1,1,n,t2);
    build1(1,1,n,t3);
    while(q--){
        int p;
        cin>>p;
        if(p==1){
            int l,r,x;
            cin>>l>>r>>x;
            update1(1,1,n,l,r,(x-l)*(x-l),t1);
            update1(1,1,n,l,r,2*(x-l),t2);
            update1(1,1,n,l,r,1,t3);
        }
        else{
            int pos;
            cin>>pos;
            int ans=a[pos]+get1(1,1,n,pos,t1)+(pos*get1(1,1,n,pos,t2))+ (pos*pos*get1(1,1,n,pos,t3));
            cout<<ans<<"\n";
        }
    }
}