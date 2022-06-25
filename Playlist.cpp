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

void solve(){
    int n;
    cin >> n;
    map< int, int> mp;
    int j = 0, ans = 0, temp;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]] = -1;
    }
    for(int i = 0; i < n; i++){
        if(mp[v[i]] == -1){
            // if(i == 5){
            //     cout << "Yes";
            // }
            ans = max( ans, i - j + 1);
            // cout << i << " " << j << '\n';
            if(i - j + 1 == 3){
                cout << i << " " << j << "\n";
            }
        }
        else{
            while(j <= mp[v[i]]){
                mp[j] = -1;
                j++;
            }
        }
        mp[v[i]] = i;
    }
    cout << ans << "\n";
}

int32_t main(){
    solve();    
}