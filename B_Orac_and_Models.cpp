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

int32_t main() 
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1]={};
        for(int i=1;i<n+1;i++)cin>>a[i];
        vi ans(n+1,1);
        for(int i=1;i<n+1;i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    if(a[j]<a[i]){
                        ans[i]=max(ans[i],ans[j]+1);
                    }
                    if(a[i/j]<a[i]){
                        ans[i]=max(ans[i],ans[i/j]+1);
                    }
                }
            }
        }

        sort(ans.begin(),ans.end());
        cout<<ans[n]<<"\n";
    }
}