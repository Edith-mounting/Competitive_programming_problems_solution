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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sparse[n][(int)log2(n)+1];
    for(int i=0;i<n;i++){
        sparse[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            if(a[sparse[i][j-1]]<a[sparse[i+(1<<(j-1))][j-1]]){
                sparse[i][j]=sparse[i][j-1];
            }
            else{
                sparse[i][j]=sparse[i+(1<<j-1)][j-1];
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int l=j-i+1;
            int k=log2(l);
            int ans=min(a[sparse[i][k]],a[sparse[i+l-(1<<k)][k]]);
            ans=ans*(l);
            maxi=max(maxi,ans);
        }
    }
    cout<<maxi<<"\n";
}

