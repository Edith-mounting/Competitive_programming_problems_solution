#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
void solve(){
    int n;
    cin >> n;
    char s[2][n];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i<n ;i++){
        if(s[0][i]=='0' && s[1][i]=='1'){
            ans+=2;
        }
        else if(s[0][i]=='1' && s[1][i]=='0'){
            ans+=2;
        }
        else if((i-1)<n && (s[0][i] == '0' && s[1][i] == '0') && (s[0][i+1] == '1' && s[1][i+1] == '1')){
            ans+=2;
            i++;
        }
        else if((i-1)<n && (s[0][i]=='1' && s[1][i]=='1') && (s[0][i+1] == '0' && s[1][i+1] == '0') ){
            ans+=2;
            i++;
        }
        else if(s[0][i]=='1' && s[1][i]=='1'){
            continue;
        }
        else{
            ans++;
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}