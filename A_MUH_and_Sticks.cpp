#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
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
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return powd(x,y/2)*powd(x,y/2);
    }
    else{
        int t=powd(x,y/2);
        return (x*t*t);
    }
}
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
void solve(){
    int a[6];
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<6;i++){
        mp[a[i]]++;
    }
    bool bl=false;
    string s;
    for(auto i:mp){
        if(i.ss>=4){
            bl=true;
        }
    }
    if(!bl){
        s="Alien";
    }
    else{
        if(mp.size()==3){
            s="Bear";
        }
        else if(mp.size()==2){
            for(auto i:mp){
                if(i.ss==1){
                    s="Bear";
                }
                else if(i.ss==2){
                    s="Elephant";
                }
            }
        }
        else{
            s="Elephant";
        }
    }
    cout<<s<<"\n";
}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }
}