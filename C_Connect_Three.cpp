#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}

int N=40000+5;
int32_t main()
{
	FIO;
    vector<pii> v;
    for(int i=0;i<3;i++){
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    sort(v.begin(),v.end());
    //Sorted till now on the basis of x-coordinate
    //ans->pointA to pointB then pointB to pointC
    // for(auto i:v){
    //     cout<<i.ff<<" "<<i.ss<<"\n";
    // }
    set<pii> ans;
    //making x-coordinate same
    for(int i=v[0].ff;i<=v[1].ff;i++){
        ans.insert({i,v[0].ss});
    }
    //making y-coordinate same 
    if(v[1].ss>=v[0].ss){
        for(int i=v[0].ss;i<=v[1].ss;i++){
            ans.insert({v[1].ff,i});
        }
    }
    else{
        for(int i=v[0].ss;i>=v[1].ss;i--){
            ans.insert({v[1].ff,i});
        }
    }
    // for(int i=v[0].ss+1;i<=v[1].ss;i++){
    //     ans.insert({v[1].ff,i});
    // }
    if(v[2].ss>v[1].ss){
        for(int i=v[1].ss;i<=v[2].ss;i++){
            ans.insert({v[1].ff,i});
        }
        for(int i=v[1].ff;i<=v[2].ff;i++){
            ans.insert({i,v[2].ss});
        }
    }
    else{
        for(int i=v[1].ss;i>=v[2].ss;i--){
            ans.insert({v[1].ff,i});
        }
        for(int i=v[1].ff;i<=v[2].ff;i++){
            ans.insert({i,v[2].ss});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }
}
