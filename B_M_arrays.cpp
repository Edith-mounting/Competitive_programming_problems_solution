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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main() 
{
    int w;
    cin>>w;
    int x[32]={};
    x[0]=1;
    for(int i=1;i<32;i++){
        x[i]=2*x[i-1];
    }
    while(w--){
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int rem[m]={};
        for(int i=0;i<n;i++){
            rem[(a[i]%m)]++;
        }
        int ans=0;
        if(m%2==0){
            if(rem[m/2]!=0){
                ans++;
            }
            if(m/2 !=0){
            if(rem[0]!=0){
                ans++;
            }}
            for(int i=1;i<m/2;i++){
                if(rem[i]!=0 || rem[m-i]!=0){
                    ans+=absk(rem[i]-rem[m-i]);
                    if(absk(rem[i]-rem[m-i])==0){
                        ans++;
                    }
                }
            }
        }
        else{
            if(rem[0]!=0){
                ans++;
            }
            for(int i=1;i<=m/2;i++){
                if(rem[i]!=0 || rem[m-i]!=0){
                    ans+=absk(rem[i]-rem[m-i]);
                    if(absk(rem[i]-rem[m-i])==0){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}