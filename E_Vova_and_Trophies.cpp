#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <map> 
#include <iomanip>
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
const double pi = acos(-1);
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
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}

int solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pii> v;
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        if((a==-1) && s[i]=='G'){
            a=i;
        }
        else if((a!=-1) && s[i]=='G'){
            continue;
        }
        else if((a==-1) && s[i]=='S'){
            continue;
        }
        else{
            b=i-1;
            v.pb({a,b});
            a=-1;
        }
    }
    if(a!=-1){
        v.pb({a,n-1});
    }
    if(v.size()==0){
        return 0;
    }
    else if(v.size()==1){
        return (v[0].ss-v[0].ff+1);
    }
    else if(v.size()==2){
        if(v[0].ss+2==v[1].ff){
            return (v[1].ss-v[1].ff+1)+(v[0].ss-v[0].ff+1);
        }
        else{
            return max(v[1].ss-v[1].ff,v[0].ss-v[0].ff)+2;
        }
    }
    else{
        int maxi=0;
        // for(auto i:v){
        //     cout<<i.ff<<" "<<i.ss<<"\n";
        // }
        for(int i=0;i<v.size();i++){
            if(i<n-1){
                if(v[i].ss+2==v[i+1].ff){
                    maxi=max(v[i+1].ss-v[i].ff+1,maxi);
                }
            }
            maxi=max(maxi,v[i].ss-v[i].ff+2);
        }
        return maxi;
    }
}
int32_t main(){
    FIO;
    cout<<solve();
}