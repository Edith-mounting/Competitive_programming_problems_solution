#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue> 
#include <iomanip>
using namespace std;

const int PI=3.14159265358;
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
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    FIO;
    int n;
    cin>>n;
    map<int,int> mp;
    vector<pii> v(n);
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>v[i].ff>>v[i].ss;
    }
    int a=v[0].ff,b=v[0].ss;
    for(int i=2;i*i<=v[0].ff;i++){
        if(a%i==0){
            while(a%i==0){
                mp[i]++;
                a/=i;
            }
        }
    }
    if(a>1){
        mp[a]++;
    }
    for(int i=2;i*i<=v[0].ss;i++){
        if(b%i==0){
            while(b%i==0){
                mp[i]++;
                b/=i;
            }
        }
    }
    if(b>1){
        mp[b]++;
    }
    int ans=-1;
    for(auto j:mp){
        bool b=true;
        for(int i=0;i<n;i++){
            if(v[i].ff%j.ff!=0 && v[i].ss%j.ff!=0){
                b=false;
                break;
            }
        }
        if(b){
            ans=j.ff;
            break;
        }
    }
    cout<<ans<<"\n";
}