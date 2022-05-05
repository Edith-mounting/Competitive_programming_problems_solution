#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
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
//#define mod             1000000007
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
    int n;
    cin>>n;
    int p=n,l=0;
    int ans=0;
    while(p>0){
        l++;
        p/=10;
    }
    for(int i=1;i<=l-1;i++){
        ans+=ow(2,i)-1;
    }
    int zerocount=0;
    p=n;
    while(p>0){
        if(p%10==0){
            zerocount++;
        }
        p/=10;
    }
    ans+=pow(2,l-zerocount)-1;
    cout<<ans<<"\n";
}