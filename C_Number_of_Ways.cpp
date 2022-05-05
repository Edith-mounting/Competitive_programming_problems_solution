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

int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int netsum=0;
    for(int i=0;i<n;i++){
        netsum+=a[i];
    }
    if(netsum%3==0){
        netsum/=3;
        int count[n];
        int k=0;
        for(int i=n-1;i>=0;i--){
            k+=a[i];
            if(k==netsum){
                count[i]=1;
            }
            else{
                count[i]=0;
            }
        }
        int sum[n];
        sum[n-1]=count[n-1];
        for(int i=n-2;i>=0;i--){
            sum[i]=sum[i+1]+count[i];
        }
        int ans=0,sum1=0;
        for(int i=0;i<n-2;i++){
            sum1+=a[i];
            if(sum1==netsum){
                ans+=sum[i+2];
            }
        }
        cout<<ans;
    }
    else{
        cout<<0;
    }
    cout<<"\n";
}