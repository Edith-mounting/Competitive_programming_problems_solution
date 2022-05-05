#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
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

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]==1){
        cout<<n+1<<" ";
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
    }
    else if(a[n-1]==0){
        for(int i=1;i<=n+1;i++){
            cout<<i<<" ";
        }
    }
    else{
        bool bl=false;
        for(int i=0;i<n-1;i++){
            if(a[i]==0 && a[i+1]==1){
                bl=true;
                break;
            }
        }
        int x=1;
        if(!bl){
            cout<<-1;
            return ;
        }
        for(int i=0;i<n-1;i++){
            if(a[i]==0 && a[i+1]==1 && bl){
                cout<<x<<" "<<n+1<<" ";
                bl=false;
            }
            else{
                cout<<x<<" ";
            }
            x++;
        }
        cout<<n;
    }
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
        cout<<"\n";
    }    
}
