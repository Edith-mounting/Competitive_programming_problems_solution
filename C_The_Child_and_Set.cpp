#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
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
    if(k<0)return -k;

    return k;
}
int32_t main(){
    int N=100000+3;
    vi v(N,0);
    int s,n;
    cin>>s>>n;
    for(int i=1;i<N;i++){
        if(i%2==1){
            v[i]=v[i-1]+1;
        }
        else{
            int j=i;
            int k=1;
            while(j%2==0){
                k=k*2;
                j/=2;
            }
            v[i]=v[i-1]+k;
        }
    }
    if(v[n]>=s){
        vector<pii> vl(n+1,{0,0});
        for(int i=1;i<=n;i++){
            vl[i].ff=(v[i]-v[i-1]);
            vl[i].ss=i;
        }
        vi ans;
        sort(vl.begin(),vl.end());
        reverse(vl.begin(),vl.end());
        for(int i=0;i<n;i++){
            if((s-vl[i].ff) >=0){
                ans.pb(vl[i].ss);
                s-=vl[i].ff;
            }
        }
        cout<<ans.size()<<"\n";
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}