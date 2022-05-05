#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int powd(int x,int y,int mod){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int q=powd(x,y/2,mod)%mod;
        return (q*q)%mod;
    }
    else{
        int q=powd(x,y/2,mod)%mod;
        return (((q*q)%mod)*x)%mod;
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        int p=log2(1e9);
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        bool b=true;
        for(int i=0;i<n;i++){
            bool kl=false;
            for(int j=0;j<=p;j++){
                if( ((powd(2,j,k)%k)*(a[i]%k))%k ==0){
                    kl=true;
                    break;
                }
            }
            if(!kl){
                b=false;
                break;
            }
        }
        if(!b){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
        cout<<"\n";
    }
}