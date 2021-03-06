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
vi bit;
int n;
void update(int index,int val){
    index++;
    while(index<=n){
        bit[index]+=val;
        index=index+ index&(-index);
    }
}
void range_add(int l,int r,int val){
    update(l,val);
    update(r+1,(-1)*val);
}
int point_query(int index){
    int ret=0;
    index++;
    while(index>0){
        ret+=bit[index];
        index=index- (index)&(-index);
    }
    return ret;
}
int sum(int index){
    int ret=0;
    index++;
    while(index>0){
        ret+=bit[index];
        index=index- index&(-index);
    }
    return ret;
}
int32_t main()
{
	FIO;
    int q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bit.clear();
    bit.resize(n+1,0);
    for(int i=0;i<n;i++){
        update(i,a[i]);
    }
    while(q--){
        int k1;
        cin>>k1;
        if(k1==1){
            // int l,r,x;
            // cin>>l>>r>>x;
            // l--,r--;
            // range_add(l,r,x);
            int l,x;
            cin>>l>>x;
            l--;
            update(l,x);
        }
        else{
            // int y;
            // cin>>y;
            // cout<<point_query(y-1)<<"\n";
            int y;
            cin>>y;
            y--;
            cout<<sum(y)<<"\n";
        }
    }
}