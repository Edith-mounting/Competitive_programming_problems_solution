#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
//#define int             long long
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
    /*int N=1000000+2;
    vi v(N,0);
    v[1]=1;
    for(int i=2;i<N;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                int k=i/j;
                if(k!=i){
                    v[i]+=2;
                }
                else{
                    v[i]+=1;
                }
            }
        }
    }*/
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int k=n/i;
                if(k!=i){
                    ans+=2;
                }
                else{
                    ans+=1;
                }
            }
        }
        cout<<ans;
        cout<<"\n";
    }
}