#include <iostream>
#include <algorithm>
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
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(auto i:mp){
        if(i.ss>=2){
            mp[2*i.ff]+=i.ss/2;
        }
        i.ss%=2;
    }
    for(auto i:mp){
        mp[i.ff]%=2;
    }
    /*for(auto i:mp){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }*/
    vi ans;
    map<int,bool> m;
    for(int i=n-1;i>=0;i--){
        if(m.find(a[i])==m.end()){
            //cout<<a[i]<<" ";
            m[a[i]]=true;
            int k=a[i];
            while(mp[k]==0){
                k=k*2;
            }
            ans.pb(k);
            mp[k]--;
        }
    }
    for(auto i:mp){
        if(i.ss>0){
            ans.pb(i.ff);
        }
    }
    //cout<<"\n";
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}