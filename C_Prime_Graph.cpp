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

void solve(){
    int n;
    cin>>n;
    int N=1011;
    vector<bool> vb(N,true);
    vb[1]=false;
    vb[0]=false;
    for(int i=2;i<N;i++){
        if(vb[i]){
            for(int j=i*i;j<N;j+=i){
                vb[j]=false;
            }
        }
    }
    int prime[1011]={};
    prime[1009]=1009;
    int p=1009;
    for(int i=1008;i>=2;i--){
        if(vb[i]){
            p=i;
            prime[i]=p;
        }
        else{
            prime[i]=p;
        }
    }
    vector<vi> adj(n+1);
    for(int i=1;i<=n;i++){
        if(i+1>n){
            adj[i].pb((i+1)%n);
        }
        else{
            adj[i].pb(i+1);
        }
    }
    int alpha=1;
    int k=prime[n]-n;
    while(k>0){
        adj[alpha].pb(alpha+2);
        k--;
        alpha++;
        if(k==0){
            break;
        }
        adj[alpha].pb(alpha+2);
        alpha+=3;
        k--;
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        for(int j:adj[i]){
            ans.pb({i,j});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }
}
int32_t main(){
    FIO;
    solve();
}