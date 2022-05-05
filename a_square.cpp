#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
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
/*bool comparator(pair<int,string> a , pair<int,string> b){
    return a.first < b.first ;
}*/
int solve(){
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int a[m+1][64];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<64;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<m+1;i++){
        int p,q=0;
        cin>>p;
        while(p>0){
            a[i][q]=p%2;
            p/=2;
            q++;
        }
    }
    for(int i=0;i<m;i++){
        int x=0;
        for(int j=0;j<64;j++){
            if(a[i][j]!=a[m][j])x++;
        }
        if(x<=k)ans++;
    }
    cout<<ans<<"\n";
}
int32_t main() 
{   
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }
}

