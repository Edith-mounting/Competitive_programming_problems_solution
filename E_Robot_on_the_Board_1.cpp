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
#define inf             100000000
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
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    int sum_x = 0, maxi_x = 0, mini_x = 0;
    int sum_y = 0, maxi_y = 0, mini_y = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'D' || s[i] == 'U'){
            if(s[i] == 'D'){
                sum_x++;
            }
            else{
                sum_x--;
            }
            maxi_x = max(maxi_x , sum_x);
            mini_x = min(mini_x , sum_x);
        }
        else{
            if(s[i] == 'R'){
                sum_y++;
            }
            else sum_y--;
            maxi_y = max(maxi_y , sum_y);
            mini_y = min(mini_y , sum_y);
        }
        if (maxi_x - mini_x >= n) {
            if (sum_x == mini_x) mini_x++;
            break;
        }
        if (maxi_y - mini_y >= m) {
            if (sum_y == mini_y) mini_y++;
            break;
        }
    }
    cout << 1 - mini_x << " " << 1 - mini_y << "\n"; 
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}