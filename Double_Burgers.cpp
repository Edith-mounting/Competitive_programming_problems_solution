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
int powx(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++){
        ans=ans*x;
    }
    return ans;
}
int solve(){
    int x,y;
    cin>>x>>y;
    if(y%x !=0){
        return -1;
    }   
    int k1=y/x;
    int ans=-1;
    for(int i=1;i<=64;i++){
        int x1=k1+i;
        int x2=0;
        while(x1>0){
            x2+=x1%2;
            x1/=2;
        }
        if(i==x2){
            ans=i;
            break;
        }
    }
    if(ans==-1){
        return -1;
    }
    int time=ans-1;
    ans=ans+y/x;
    int idx=1;
    ans/=2;
    while(ans>0){
        if(ans%2==1){
            time+=idx;
        }
        ans/=2;
        idx++;
    }
    return time;
}
int32_t main(){
    FIO;
    int w;
    cin>>w;
    while(w--){
        cout<<solve()<<"\n";
    }
}