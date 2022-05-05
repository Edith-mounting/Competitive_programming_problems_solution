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

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        vi count;
        vi number;
        sort(a,a+n);
        int kl=1;
        int i;
        for(i=1;i<n;i++){
            if(a[i]==a[i-1]){
                kl++;
            }
            else{
                number.pb(a[i-1]);
                count.pb(kl);
                kl=1;
            }
        }
        number.pb(a[n-1]);
        count.pb(kl);
        sort(count.begin(),count.end());
        int l=number.size();
        vi left(l,0);
        vi right(l,0);
        left[0]=0;
        kl=1;
        for(int i=1;i<l;i++){
            if(count[i]==count[i-1]){
                left[i]=left[i-1];
                kl++;
            }
            else{
                left[i]=left[i-1]+(kl*count[i-1]);
                kl=1;
            }
        }
        /*for(auto i:count){
            cout<<i<<" ";
        }
        cout<<"\n";
        for(auto i:left){
            cout<<i<<" ";
        }
        cout<<"\n";*/
        right[l-1]=0;
        for(int i=l-2;i>=0;i--){
            right[i]=right[i+1]+count[i+1];
        }
        /*for(auto i:right){
            cout<<i<<" ";
        }
        cout<<"\n";*/
        int ans=inf;
        for(int i=0;i<l;i++){
            ans=min(ans,left[i]+right[i]-(count[i]*(l-i-1)));
            //cout<<ans<<" ";
        }
        cout<<ans<<"\n";
    }
}