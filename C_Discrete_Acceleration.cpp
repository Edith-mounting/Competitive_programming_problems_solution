#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define lld             long double
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,l;
        cin>>n>>l;
        int a[n+2];
        a[0]=0;
        a[n+1]=l;
        for(int i=1;i<n+1;i++){
            cin>>a[i];
        }
        lld t1[n+2];
        t1[0]=0;
        for(int i=1;i<n+2;i++){
            t1[i]=(lld)(a[i]-a[i-1])/(i) + t1[i-1];
        }
        lld t2[n+2];
        t2[n+1]=0;
        for(int i=n;i>=0;i--){
            t2[i]=(lld)(a[i+1]-a[i])/(n-i+1) +t2[i+1];
        }
        /*for(int i=0;i<n+2;i++){
            cout<<t2[i]<<" ";
        }*/
        int index;
        for(int i=0;i<n+2;i++){
            if(t1[i]-t2[i]>1e-5){
                index=i;
                break;
            }
        }
        //cout<<index<<"\n";
        int a1=index,b1=n-index+2;
        lld kl=(lld)b1*(t1[index-1]-t2[index]);
        lld ans=t1[index-1]+(lld)((lld)a[index]-(lld)a[index-1]-kl)/(n+2);
        cout<<fixed;
        cout<<setprecision(10)<<ans<<"\n";
    }
}