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
    int t;
    cin>>t;
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;
        int x[k],y[k];
        int count1=0;
        vector<int> v1(a+1,0);
        vector<int> v2(b+1,0);
        for(int i=0;i<k;i++){
            cin>>x[i];
            v1[x[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>y[i];
            v2[y[i]]++;
        }
        int kl=(k*(k-1))/2;
        for(int i=0;i<a+1;i++){
            if(v1[i]>=2){
                kl-=(v1[i]*(v1[i]-1))/2;
            }
        }
        for(int i=0;i<b+1;i++){
            if(v2[i]>=2){
                kl-=(v2[i]*(v2[i]-1))/2;
            }
        }
        cout<<kl<<"\n";
    } 
}