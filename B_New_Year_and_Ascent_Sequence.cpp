#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <stack>
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
#define w(x)            int x; cin>>x; whiles(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int n;
    cin>>n;
    vi a[n];
    vi maxi;
    int ans=0;
    vector<int> mini(n,0);
    vector<int> maxi1(n,0);
    vector<bool> vis(n,false);
    int count1=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int kl;
            cin>>kl;
            a[i].pb(kl);
        }
        int small=a[i][0];
        bool bl=false;
        int ma=small;
        for(int j=1;j<k;j++){
            if(small<a[i][j]){
                bl=true;
                break;
            }
            else{
                small=a[i][j];
            }
            ma=max(ma,a[i][j]);
        }
        if(bl){
            ans+=2*(n-count1-1)+1;
            count1++;
            //cout<<ans<<"\n";
            vis[i]=true;
        }
        else{
            maxi.pb(ma);
            maxi1[i]=ma;
            mini[i]=small;
        }
    }
    //cout<<ans<<"\n";
    sort(maxi.begin(),maxi.end());
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int>::iterator upper;
            upper=upper_bound(maxi.begin(), maxi.end(), mini[i]);
            ans+=(maxi.end()-upper);
        }
        //cout<<i<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
} 