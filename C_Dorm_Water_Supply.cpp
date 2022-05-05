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
struct st
{
    int x1,x2,d;
};
bool comp(st a,st b){
    return a.x1<b.x1;
}
void solve(){
    int n,p;
    cin>>n>>p;
    vi v(n+1,0);
    vi vl(n+1,0);
    int m[n+1][n+1];
    int a[p],b[p];
    vector<st> input(p);
    for(int i=0;i<p;i++){
        cin>>input[i].x1>>input[i].x2>>input[i].d;
    }
    sort(input.begin(),input.end(),comp);
    for(int i=0;i<p;i++){
        int a=input[i].x1,b=input[i].x2;
        m[a][b]=input[i].d;
        v[a]=b;
        vl[a]++;
        vl[b]-=1;
        v[b]=0;
    }
    vector<st> ans;
    for(int i=1;i<n+1;i++){
        if(vl[i]==1){
            int k=i;
            int mini=inf;
            while(true){
                mini=min(m[k][v[k]],mini);
                k=v[k];
                if(vl[k]==-1){
                    ans.pb({i,k,mini});
                    break;
                }
            }
        }
    }
    sort(ans.begin(),ans.end(),comp);
    cout<<ans.size()<<"\n";
    for(st i:ans){
        cout<<i.x1<<" "<<i.x2<<" "<<i.d<<"\n";
    }
}
int32_t main(){
    FIO;
    solve();
}