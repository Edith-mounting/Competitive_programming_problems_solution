#include <iostream>
#include <algorithm>
#include <iomanip>
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
struct help{
    int x0=0,x1=0;
};
bool comp(help x,help y){
    return absk(x.x0-x.x1)<absk(y.x0-y.x1);
}
void solve(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<help> a(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            if(s[i][j]=='0'){
                a[i].x0++;
            }
            else{
                a[i].x1++;
            }
        }
    }
    //ans is either n or n-1
    bool bl=false;
    for(int i=0;i<n;i++){
        if((a[i].x0 + a[i].x1)%2==1){
            bl=true;
        }
    }
    if(bl){
        cout<<n<<"\n";
    }
    else{
        int c1=0;
        for(int i=0;i<n;i++){
            if((a[i].x0 + a[i].x1)%2==0){
                if(a[i].x0%2==1){
                    c1++;
                }
            }
        }
        if(c1%2==1){
            cout<<n-1;
        }
        else{
            cout<<n;
        }
        cout<<"\n";
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        solve();
    }
}