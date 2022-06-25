#include <bits/stdc++.h>
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
int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> fact(n + 1, 0);
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i]*i)%mod;
    }
    vector<int> gcd1(n + 1, 0);
    for(int i = 1; i <= n; i++){
        gcd1[i] = gcd(i, i + 1);
    }
    int one = -1, zero = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(zero == -1){
                zero = i;
            }
        }
        else if(s[i] == '1'){
            one = i;
        }
    }
    int ans = 0;
    if(one == -1){
        if(zero == -1){
            ans = n;
        }
        else{
            ans = zero + 1;
        }
    }
    else if(zero == -1){
        ans = n - one;
    }
    else{
        ans = zero - one + 1;
    }
    cout << ans <<"\n";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)
        solve();    
}