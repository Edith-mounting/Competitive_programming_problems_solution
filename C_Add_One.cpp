#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
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
    FIO;
    int N=200000+5;
    int dp[N]={};
    for(int i=0;i<N;i++){
        if(i<=8){
            dp[i]=2;
        }
        else if(i==9){
            dp[i]=3;
        }
        else{
            dp[i]=(dp[i-9]+dp[i-10])%mod;
        }
    }
    int w;
    cin>>w;
    while(w--){
        string s;
        int m;
        cin>>s>>m;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(m+(int)(s[i]-'0')<10){
                ans=(ans+1)%mod;
            }
            else{
                ans=(ans+dp[m-10+(int)(s[i]-'0')])%mod;
            }
        }
        cout<<ans<<"\n";
    }

}