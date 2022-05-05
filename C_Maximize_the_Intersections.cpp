#include <iostream>
#include <algorithm>
#include <map>
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


int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        int a[2*n+1]={};
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            a[x]=y;
            a[y]=x;
        }
        vi v;
        for(int i=1;i<=2*n;i++){
            if(a[i]==0){
                v.pb(i);
            }
        }
        for(int i=0;i<(n-k);i++){
            a[v[i]]=v[i+n-k];
            a[v[i+n-k]]=v[i];
        }
        int ans=0;
        for(int i=1;i<=2*n;i++){
            for(int j=i+1;j<=2*n;j++){
                if(i!=j){
                    if((j<i && a[j]<i) || (j<a[i] && a[j]<i)){
                        ans++;
                    }
                }    
            }
        }
        cout<<ans<<"\n";
    }
}