#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
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
void solve(){
	int n;
    cin>>n;
    int dp[n+1]={};
    for(int i=1;i<=n;i++){
        int k=i,maxi=0;
        while(k>0){
            maxi=max(maxi,k%10);
            k/=10;
        }
        dp[i]=dp[i-maxi]+1;
    }
    cout<<dp[n]<<"\n";
}
int32_t main(){
	int w=1;
	while(w--){
		solve();
	}
}


