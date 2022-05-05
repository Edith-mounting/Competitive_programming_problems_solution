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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,u,v;
        cin>>n>>u>>v;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        bool b=false;
        for(int i=1;i<n;i++){
            if(a[i-1]!=a[i]){
                b=true;
            }
        }
        if(b){
            bool kl=false;
            for(int i=0;i<n-1;i++){
                if(absk(a[i+1]-a[i])>=2){
                    kl=true;
                    break;
                }   
            }
            if(kl){
                cout<<0;
            }
            else{
                cout<<min(u,v);
            }
        }
        else{
            cout<<min(2*v,v+u);
        }
        cout<<"\n";
    }
}