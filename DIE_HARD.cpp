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
int dp[2000][2000];
int die_hard(int step,int h,int a){
    if(h<1 || a<1){
        return 0;
    }
    if(dp[h][a]!=-1){
        return dp[h][a];
    }
    if(step){
        return die_hard(0,h+3,a+2)+1;
    }
    dp[h][a]=max(die_hard(1,h-20,a+5),die_hard(1,h-5,a-10))+1;
    return dp[h][a];
}
int32_t main(){
    int w=1;
    cin>>w;
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            dp[i][j]=-1;
        }
    }
    while(w--){
        int h,a;
        cin>>h>>a;
        cout<<die_hard(0,h+3,a+2)<<"\n";          
    }
}