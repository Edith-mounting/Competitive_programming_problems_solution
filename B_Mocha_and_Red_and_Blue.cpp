#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
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
    cin>>n;
    bool bl=false;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i]=='R' || s[i]=='B'){
            bl=true;
        }
    }
    if(!bl){
        for(int i=0;i<n;i++){
            if(i%2==0){
                cout<<'R';
            }
            else{
                cout<<'B';
            }
        }
        cout<<"\n";
        return;
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(s[i]!='?'){
            v.pb(i);
        }
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=v[i]+1;j<v[i+1];j++){
            if(s[j-1]=='R'){
                s[j]='B';
            }
            else{
                s[j]='R';
            }
        }
    }
    for(int j=v[0]-1;j>=0;j--){
        if(s[j+1]=='R'){
            s[j]='B';
        }
        else{
            s[j]='R';
        }
    }
    for(int j=v[v.size()-1]+1;j<n;j++){
        if(s[j-1]=='R'){
            s[j]='B';
        }
        else{
            s[j]='R';
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<"\n";
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
