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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}

void solve(){
    int n,x;
    cin>> n>> x;
    vector<int > a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    int ans=0,count=0;
    for(auto i:mp){
        ans=max(ans,i.ss);
    }
    if(x==0){
        cout<<ans<<" "<<0<<"\n";
        return ;
    }
    for(auto i:mp){
        int temp=i.ff;
        temp = (temp^x);
        if(mp.find(temp) != mp.end()){
            if(mp[temp]+i.ss==ans){
                count=min(count,i.ss);
            }
            else if(mp[temp] + i.ss > ans){
                ans=mp[temp] + i.ss;
                count=i.ss;
            }
        }
    }
    if(count == inf){
        cout<<ans<<" "<<0<<"\n";
    }
    else{
        cout<<ans<<" "<<count<<"\n";
    }
   
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        solve();
    }
}