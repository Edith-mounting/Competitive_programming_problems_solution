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
    FIO;
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<n;j++)cin>>b[j];
    vi sum(n,0);
    sum[0]=a[0]*b[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+ a[i]*b[i];
    }
    int maxi=sum[n-1];
    for(int c=0;c<n;c++){
        int cur=0;
        //for odd length
        int l=c,r=c;
        while(l>=0 && r<=(n-1)){
            if(l==r){
                cur+=a[l]*b[r];
            }
            else{
                cur+=a[l]*b[r]+a[r]*b[l];
            }
            int comp=0;
            comp+=cur;
            if(l!=0){
                comp+=sum[l-1];
            }
            comp+=(sum[n-1]-sum[r]);
            maxi=max(maxi,comp);
            l--;r++;
        }
        cur=0;
        l=c,r=c+1;
        while(l>=0 && r<=(n-1)){
            cur+=a[r]*b[l]+a[l]*b[r];
            int comp=0;
            comp+=cur;
            if(l!=0){
                comp+=sum[l-1];
            }
            comp+=(sum[n-1]-sum[r]);
            maxi=max(maxi,comp);
            l--,r++;
        }
    }
    cout<<maxi<<"\n";
}