#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int n=1000000+2;
    vi d(n,0);
    for(int i=0;i<n;i++){
        d[i]=i;
    }
    vi pr;
    for(int i=2;i<n;i++){
        if(d[i]==i){
            pr.pb(i);
        }
        for(int j=0;j<((int)pr.size()) && (pr[j]<=d[i]) && (i*pr[j]<n);j++){
            d[i*pr[j]]=pr[j];
        }
    }
    vi prime(n,0);
    prime[2]=1;
    for(int i=3;i<n;i++){
        if(d[i]==i){
            prime[i]=prime[i-1]+1;
        }
        else{
            prime[i]=prime[i-1];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(prime[x]<=y){
            cout<<"Chef";
        }
        else{
            cout<<"Divyam";
        }
        cout<<"\n";
    }
}