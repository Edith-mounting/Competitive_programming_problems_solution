#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>
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

int32_t main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        mp[a[0][i]]=1;
    }
    for(int i=1;i<n;i++){
        map<int,int> ml;
        for(int j=0;j<m;j++){
            ml[a[i][j]]++;
        }
        for(auto i:ml){
            if(mp.find(i.ff)!=mp.end()){
                mp[i.ff]++;
            }
        }
    }
    for(auto i:mp){
        if(i.ss==n){
            cout<<i.ff<<" ";
        }
    }
    cout<<"\n";
}