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
bool comp(pii x,pii y){
    return y.ss>x.ss;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        if(n==1){
            cout<<1<<"\n";
            cout<<1<<"\n";
        }
        else{
            vector<pii> v;
            for(int i=0;i<n;i++){
                v.pb({i+1,a[i]});
            }
            sort(v.begin(),v.end(),comp);
            int sum=v[0].ss;
            int index=0;
            for(int i=1;i<n;i++){
                if(v[i].ss <= sum){
                    sum+=v[i].ss;
                    continue;
                }
                else{
                    sum+=v[i].ss;
                    index=i;
                }
            }
            vi ans;
            for(int i=index;i<n;i++){
                ans.pb(v[i].ff);
            }
            cout<<ans.size()<<"\n";
            sort(ans.begin(),ans.end());
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}