#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int32_t main() 
{   
    int w;
    cin>>w;
    while(w--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum==x){
            cout<<"NO\n";
            continue;
        }
        else{
            cout<<"YES\n";
        }
        sort(a,a+n,greater<int>());
        if(a[0]==x){
            cout<<a[1]<<" "<<a[0]<<" ";
            for(int i=2;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            vi ans;
            int sum1=0;
            bool bl=false;
            for(int i=0;i<n;i++){
                sum1+=a[i];
                ans.pb(a[i]);
                if(bl){
                    swap(ans[ans.size()-1],ans[ans.size()-2]);
                    bl=false;
                }
                if(sum1==x){
                    bl=true;
                }
            }
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout<<"\n";
        }
    }
}