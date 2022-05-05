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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
struct help{
    int x1,y1,i1;
};
bool f(char a,char a1,char a2 ,char a3,char a4){
    if(a=='*' && a1=='*' && a2=='*' && a3=='*' && a4=='*'){
        return true;
    }
    return false;
}
bool comp(help x,help y){
    if(x.i1!=y.i1){
        return x.i1<y.i1;
    }
    else{
        if(x.x1!=y.x1){
            return x.x1<y.x1;
        }
        else{
            return x.y1<y.y1;
        }
    }
}
const int N=800000+5;
int t[N];
int n,q;
void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
    }
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=min(t[v*2],t[v*2 +1]);
    }
}
void update(int v,int tl,int tr,int pos,int new_val){
    if(tl==tr){
        t[v]=new_val;
    }
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }
        else{
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        t[v]=min(t[v*2],t[v*2+1]);
    }
}
int mini(int v,int tl,int tr,int l,int r){
    if(l>r){
        return inf;
    }
    if((l==tl) && (r==tr)){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return min(mini(v*2,tl,tm,l,min(r,tm)),mini(v*2+1,tm+1,tr,max(l,tm+1),r));
}
int32_t main()
{
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<N;i++){
        t[i]=inf;
    }
    build(a,1,0,n-1);
    // for(int i=1;i<=15;i++){
    //     cout<<t[i]<<" ";
    // }
    while(q--){
        int k;
        cin>>k;
        if(k==1){
            int x,y;
            cin>>x>>y;
            update(1,0,n-1,x-1,y);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<mini(1,0,n-1,l,r)<<"\n";
        }
    }
}
