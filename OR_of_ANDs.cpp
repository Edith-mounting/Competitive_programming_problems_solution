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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y&1){
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (t*t)%mod;
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b[32]={};
        for(int i=0;i<n;i++){
            int k=a[i],p=0;
            while(k>0){
                b[p]+=k%2;
                p++;
                k/=2;
            }
        }
        int ans=0,y=1;
        for(int i=0;i<32;i++){
            if(b[i]>0){
                ans+=y;
            }
            y=y*2;
        }
        cout<<ans<<"\n";
        while(q--){
            int x,v;
            cin>>x>>v;
            x--;
            int p=0;
            while(a[x]>0){
                b[p]-=a[x]%2;
                p++;
                a[x]/=2;
            }
            p=0;
            a[x]=v;
            while(v>0){
                b[p]+=v%2;
                p++;
                v/=2;
            }
            int ans=0,y=1;
            for(int i=0;i<32;i++){
                if(b[i]>0){
                    ans+=y;
                }
                y=y*2;
            }
            cout<<ans<<"\n";
        }
    }
}