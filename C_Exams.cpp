#include <iostream>
#include <algorithm>
#include <vector>
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool comp(pii x,pii y){
    if(x.ff!=y.ff){
        return x.ff<y.ff;
    }
    else{
        return x.ss<y.ss;
    }
}
int32_t main(){
    int n;
    cin>>n;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    sort(v.begin(),v.end(),comp);
    /*for(int i=0;i<n;i++){
        cout<<v[i].ff<<" "<<v[i].ss<<"\n";
    }*/
    int maxi=v[0].ss;
    for(int i=0;i<n;i++){
        if(v[i].ss>=maxi){
            maxi=v[i].ss;
        }
        else{
            maxi=v[i].ff;
        }
    }
    cout<<maxi<<"\n";
}