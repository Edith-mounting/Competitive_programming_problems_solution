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
void solve(){
    int t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    int k1=ex-sx;
    int k2=ey-sy;
    string st;
    cin>>st;
    int s=0,n=0,e=0,w=0;
    int ans=0;
    bool b1=false,b2=false;
    if(k1==0){
        b1=true;
    }
    if(k2==0){
        b2=true;
    }
    for(int i=0;i<t;i++){
        if(st[i]=='S'){
            s++;
            if(k2<=0){
                if(absk(k2)==s){
                    b2=true;
                    ans=max(ans,i+1);
                }
            }
        }
        else if(st[i]=='N'){
            n++;
            if(k2>=0){
                if(k2==n){
                    b2=true;
                    ans=max(ans,i+1);
                }
            }
        }
        else if(st[i]=='E'){
            e++;
            if(k1>=0){
                if(k1==e){
                    b1=true;
                    ans=max(ans,i+1);
                }
            }
        }
        else{
            w++;
            if(k1<=0){
                if(absk(k1)==w){
                    b1=true;
                    ans=max(ans,i+1);
                }
            }
        }
    }
    if(b1 && b2){
        cout<<ans;
    }
    else{
        cout<<-1;
    }
}
int32_t main(){
    FIO;
    solve();
}