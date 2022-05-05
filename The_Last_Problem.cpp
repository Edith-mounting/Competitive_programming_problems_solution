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
int n=1005;
void solve(){
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        int d=i;
        a[i][1]=a[i-1][1]+d;
        for(int j=2;j<n;j++){
            a[i][j]=a[i][j-1]+d;
            d++;
        }
    }
    int w;
    cin>>w;
    while(w--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans=0;
        for(int i=x1;i<x2;i++){
            ans+=a[i][y1];
        }
        for(int i=y1;i<=y2;i++){
            ans+=a[x2][i];
        }
        cout<<ans<<"\n";
    }
}
int32_t main(){
    FIO;
    solve();
}