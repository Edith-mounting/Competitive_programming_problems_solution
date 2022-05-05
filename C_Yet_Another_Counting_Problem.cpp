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

int32_t main() 
{
    int w;
    cin>>w;
    while(w--){
        int a,b,q;
        cin>>a>>b>>q;
        int x[a*b];
        int n=a*b;
        for(int i=0;i<(a*b);i++){
            if((i%a)%b==(i%b)%a){
                x[i]=0;
            }
            else{
                x[i]=1;
            }
        }
        int k=0;
        for(int i=0;i<a*b;i++){
            k+=x[i];
        }
        int sum[n]={};
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+x[i];
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            int ans=0;
            if(l==0){
                ans=(r/n)*k + sum[r%n];
            }
            else{
                ans=(r/n)*k -(l/n)*k + sum[r%n]-sum[l%n];
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}