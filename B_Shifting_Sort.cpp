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
    int a[n];
    for(int i = 0; i<n ; i++){
        cin >> a[i];
    }
    vector<vector<int> > ans;
    int l , r;
    for(int i=1;i<n;i++){
        int index = -1;
        for(int j = i-1;j>=0;j--){
            if(a[j] < a[i]){
                index = j;
                break;
            }
        }
        l = index + 1;
        r = i;
        int x = a[l];
        for(int i = l+1;i<=r;i++){
            int y = a[i];
            a[i] = x;
            x = y;
        }
        a[l] = x;
        if(r-l >0){
            vector<int> temp;
            temp.push_back(l + 1);
            temp.push_back(r + 1);
            temp.push_back( r - l);
            ans.push_back(temp);
        }
    }
    cout<< ans.size()<<"\n";
    for(vector<int> i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}