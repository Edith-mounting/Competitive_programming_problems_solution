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
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int c[n],a[n],b[n];
        for(int i=0;i<n;i++)cin>>c[i];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int sum[n]={};
        sum[0]=0;
        for(int i=1;i<n;i++){
            if(a[i]==b[i]){
                sum[i]+=(c[i]-1)+2;
            }
            else if(a[i]>b[i]){
                sum[i]+=(c[i]-1)+2+(c[i-1]-a[i])+(b[i]-1);
                if(i==1){
                    int k=(c[i]-1)+2+(a[i]-b[i]);
                    sum[i]=k;
                }
                else{
                    int k=(c[i]-1)+2+(a[i]-b[i]);
                    sum[i]+=(sum[i-1]-c[i-1]+1);
                    sum[i]=max(sum[i],k);
                }
            }
            else{
                sum[i]+=(c[i]-1)+2+(a[i]-1)+(c[i-1]-b[i]);
                if(i==1){
                    int k=(c[i]-1)+2+(b[i]-a[i]);
                    sum[i]=k;
                }
                else{
                    int k=(c[i]-1)+2+(b[i]-a[i]);
                    sum[i]+=(sum[i-1]-c[i-1]+1);
                    sum[i]=max(sum[i],k);
                }
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            //cout<<sum[i]<<" ";
            x=max(x,sum[i]);
        }
        //cout<<"\n";
        cout<<x;
        cout<<"\n";
    }
}