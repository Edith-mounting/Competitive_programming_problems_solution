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
const int maxi=52;
int a[maxi][maxi];
bool vis[maxi][maxi];
set<pii> s1;
set<pii> s2;
int x[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs1(int x1,int y1,int p){
    vis[x1][y1]=true;
    pii k;
    k.ff=x1,k.ss=y1;
    if(p==0){
        s1.insert(k);
    }
    else{
        s2.insert(k);
    }
    for(int i=0;i<4;i++){
        int x2,y2;
        x2=x1+x[i][0],y2=y1+x[i][1];
        if(!vis[x2][y2] && a[x2][y2]==0){
            dfs1(x2,y2,p);
        }
    }
}
int32_t main(){
    FIO;
    int n;
    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    for(int i=0;i<maxi;i++){
        for(int j=0;j<maxi;j++){
            a[i][j]=1;
            vis[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char p;
            cin>>p;
            if(p=='0'){
                a[i][j]=0;
            }
            else{
                a[i][j]=1;
            }
        }
    }
    dfs1(r1,c1,0);
    dfs1(r2,c2,1);
    int ans=inf;
    for(auto i:s1){
        for(auto j:s2){
            int l=(i.ff-j.ff)*(i.ff-j.ff) + (i.ss-j.ss)*(i.ss-j.ss);
            ans=min(ans,l);
        }
    }
    cout<<ans<<"\n";
}
