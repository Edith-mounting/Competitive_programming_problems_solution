#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='0'){
            a[i]=-1;
        }
        else{
            a[i]=1;
        }
    }
    int sum[n]={};
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[sum[i]].pb(i);
    }
    int maxi=0;
    for(auto i:mp){
        if(i.ss.size()>1){
            maxi=max(maxi,(i.ss)[i.ss.size()-1]-(i.ss)[0]);
        }
    }
    if(mp.find(0)!=mp.end()){
        maxi=max(maxi,mp[0][mp[0].size()-1]+1);
    }
    cout<<maxi<<"\n";
}