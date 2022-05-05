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
int32_t main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int> v;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(n/i ==i){
                v.pb(i);
            }
            else{
                v.pb(i);
                v.pb(n/i);
            }
        }
    }
    map<int,int> mp;
    int k=n;
    while(k>0){
        mp[k%10]++;
        k/=10;
    }
    for(auto i:v){
        bool b=false;
        int kl=i;
        while(kl>0){
            if(mp.find(kl%10)!=mp.end()){
                b=true;
                break;
            }
            kl/=10;
        }
        if(b){
            ans++;
        }
    }
    cout<<ans<<"\n";
}