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
    int n,m,d;
    cin>>n>>m>>d;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vi v(n*m);
    int k=0;
    bool b=true;
    int k1=a[0][0]%d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[k]=a[i][j];
            k++;
            if(a[i][j]%d !=k1){
                b=false;
            }
        }
    }
    sort(v.begin(),v.end());
    int ml=n*m/2;
    int ans=0;
    for(int i=0;i<ml;i++){
        ans+=(v[ml]-v[i]);
    }
    for(int i=ml;i<n*m;i++){
        ans+=(v[i]-v[ml]);
    }
    if(b){
        cout<<ans/d;
    }
    else{
        cout<<-1;
    }
    cout<<"\n";
}