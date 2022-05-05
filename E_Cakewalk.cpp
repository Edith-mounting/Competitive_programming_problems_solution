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
bool com(pii a,pii b){
    int x1=a.ff+a.ss;
    int x2=b.ff+b.ss;
    if(x1>x2){
        return x1<x2;
    }
    else if(x1==x2){
        return a.ff<b.ff;
    }
    else{
        return x2>x1; 
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<pii> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='*'){
                v.pb({i,j});
            }
        }
    }
    sort(v.begin(),v.end(),com);
    int x=0,y=0;
    int ans=0;
    for(int i=0;i<v.size();i++){
        if(v[i].ff>=x && v[i].ss>=y){
            ans++;
            x=v[i].ff;
            y=v[i].ss;
        }
    }
    cout<<ans<<"\n";
}