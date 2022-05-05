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
    int s[n];
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        s[i]=(c-'0');
    }
    int a[10];
    for(int i=1;i<10;i++){
        cin>>a[i];
    }
    bool b=false;
    for(int i=0;i<n;i++){
        if(a[s[i]]>s[i]){
            b=true;
            s[i]=a[s[i]];
        }
        else if(b && a[s[i]]==s[i]){
            continue;
        }
        else{
            if(b){
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
}
int32_t main(){
    FIO;
    solve();
}