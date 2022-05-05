#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
        int t=powd(x,y/2)%mod;
        return (t*t);
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
struct help{
    int x,y,dir;
};
int n,m;
bool solve(){
    string a[n][m];
    bool vis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=false;
        }
    }
    pii final,initial;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='S'){
                initial.ff=i,initial.ss=j;
            }
            if(a[i][j]=='T'){
                final.ff=i,final.ss=j;
            }
        }
    }
    vector<help> zero;
    int x1=initial.ff,y1=initial.ss;
    while(true){
        if(x1+1<m){
            x1++;
            if(a[x1][y1]=='.'){
                zero.pb({x1,y1,1});
                vis[x1][y1]=true;
            }
            else if(a[x1][y1]=='T'){
                return true;
            }
            else{
                break;
            }
        }
    }
    x1=initial.ff;
    while(true){
        if(y1+1<n){
            y1++;
            if(a[x1][y1]=='.'){
                zero.pb({x1,y1,2});
                vis[x1][y1]=true;
            }
            else if(a[x1][y1]=='T'){
                return true;
            }
            else{
                break;
            }
        }
    }
    y1=initial.ss;
    while(true){
        if(x1-1>=0){
            x1--;
            if(a[x1][y1]=='.'){
                zero.pb({x1,y1,3});
                vis[x1][y1]=true;
            }
            else if(a[x1][y1]=='T'){
                return true;
            }
            else{
                break;
            }
        }
    }
    x1=initial.ff;
    while(true){
        if(y1-1>=0){
            y1--;
            if(a[x1][y1]=='.'){
                zero.pb({x1,y1,4});
                vis[x1][y1]=true;
            }
            else if(a[x1][y1]=='T'){
                return true;
            }
            else{
                break;
            }
        }
    }
    vector<help> one;
    for(int i=0;i<zero.size();i++){
        int starti=zero[i].x,startj=zero[i].y,dire=zero[i].dir;
        
    }
}
int32_t main(){
    cin>>n>>m;
    if(solve()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}