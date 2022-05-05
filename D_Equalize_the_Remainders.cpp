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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}

int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        int n,m;
        cin>>n>>m;
        int k=n/m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> v(m,k);
        vector<pii> v1;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(v[a[i]%m]>0){
                vis[i]=true;
                v[a[i]%m]--;
            }
            else{
                if(!vis[i]){
                    v1.pb({a[i]%m,i});
                }
            }
        }
        int i1=0;
        sort(v1.begin(),v1.end());
        
    }  
}