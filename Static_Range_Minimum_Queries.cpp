#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() 
{
    /*int sparse[n][(int)log2(n)+1];
    for(int i=0;i<n;i++){
        sparse[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            if(a[sparse[i][j-1]]<a[sparse[i+(1<<(j-1))][j-1]]){
                sparse[i][j]=sparse[i][j-1];
            }
            else{
                sparse[i][j]=sparse[i+(1<<j-1)][j-1];
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        int l=y-x+1;
        int k=(int)log2(l);
        cout<<min(a[sparse[x][k]],a[sparse[x+l-(1<<k)][k]]);
        cout<<"\n";
    }*/
  
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int len = (int) sqrt (n) + 1;
    vi b(len,inf);
    for(int i=0;i<n;i++){
        b[i/len]=min(b[i/len],a[i]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int c_l = l / len,   c_r = r / len;
        int ans=inf;
        if(c_l==c_r){
            for(int i=l;i<=r;++i){
                ans=min(ans,a[i]);
            }
        }
        else{
            for(int i=l;i<=(c_l+1)*len -1;++i){
                ans=min(ans,a[i]);
            }
            for(int i=c_l+1;i<=c_r-1;++i){
                ans=min(ans,b[i]);
            }
            for(int i=c_r*len;i<=r;++i){
                ans=min(ans,a[i]);
            }
        }
        cout<<ans<<"\n";
    }
}