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

int32_t main()
{
    unsigned int l,r,k;
    cin>>l>>r>>k;
    vi v;
    bool bl=true;
    unsigned int p=1,q;
    while(p<l){
        q=p*k;
        if(q/p !=k){
            bl=false;
            break;
        }
        p=q;
    }
    if(bl){
        while(p<=r){
            v.pb(p);
            q=p*k;
            if(q/p !=k){
                break;
            }
            p=q;
        }
    }
    if(v.size()==0){
        cout<<-1;
    }
    else{
        for(auto i:v){
            cout<<i<<" ";
        }
    }
}