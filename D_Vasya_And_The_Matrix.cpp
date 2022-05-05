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

int32_t main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=0;
        }
    }
    int x1=a[0],x2=b[0];
    for(int i=1;i<n;i++){
        x1=x1^a[i];
    }
    for(int i=1;i<m;i++){
        x2=x2^b[i];
    }
    if(x1!=x2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        int x1=a[0];
        for(int i=1;i<m;i++){
            x1=x1^b[i];
        }
        ans[0][0]=x1;
        for(int i=1;i<m;i++){
            ans[0][i]=b[i];
        }
        for(int i=1;i<n;i++){
            ans[i][0]=a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}