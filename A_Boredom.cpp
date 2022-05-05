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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int j=powd(x,y/2);
        return (j*j);
    }
    else{
        int j=powd(x,y/2);
        return (((j*j))*(x));
    }
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int N=100000+2;
    vi v(N,0);
    for(int i=0;i<n;i++){
        v[a[i]]++;
    }
    vi sum(N,0);
        sum[1]=1*v[1];
        sum[2]=2*v[2];
        sum[3]=3*v[3]+sum[1];
        for(int i=4;i<N;i++){
            sum[i]=max(sum[i-2],sum[i-3])+i*v[i];
        }
        int maxi=0;
        for(int i=0;i<N;i++){
            maxi=max(maxi,sum[i]);
        }
    cout<<maxi<<"\n";
}