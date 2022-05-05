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
    int req_prata;
    cin >> req_prata;
    int n;
    cin >> n;
    int k;
    priority_queue<pii , vector<pii> , greater<pii>> pq;
    for(int i =0 ; i < n ; i++){
        cin >> k;
        pq.push({k,1});
    }
    int ans = 0;
    while(req_prata--){
        pii min_time = pq.top();
        pq.pop();
        min_time.ss++;
        pq.push({min_time.ff*min_time.ss,min_time.ss});
        ans += min_time.ff;
    }
    cout << ans;
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
        cout<<"\n";
    }
}