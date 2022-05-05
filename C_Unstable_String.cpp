#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <iomanip>
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define vip             vector<pair<int,double>>
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
struct help{
    int x1,x2,index;
};
bool comp(help a,help b){
    if(a.x1!=b.x1){
        return a.x1<b.x1;
    }
    else{
        return b.x2<a.x2;
    }
}
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int dp[n+1][2];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            dp[i+1][1]=dp[i][0]+1;
        }
        else if(s[i]=='0'){
            dp[i+1][0]=dp[i][1]+1;
        }
        else{
            dp[i+1][1]=dp[i][0]+1;
            dp[i+1][0]=dp[i][1]+1;
        }
        ans+=max(dp[i+1][0],dp[i+1][1]);
    }
    cout<<ans;
}
int32_t main()
{
	FIO;
	int w;
	cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}

}
