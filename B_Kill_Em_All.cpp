#include <iostream>
#include <algorithm>
#include <map>
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
        return (t*t*x);
    }
}
int log3(int a,int b){
    int k=a;
    if(b<a){
        return 0;
    }
    if(b==a){
        return 1;
    }
    for(int i=2;i<=40;i++){
        k=k*a;
        if(k>b){
            return i-1;
        }
        if(k==b){
            return i;
        }
    }
    return 0;
}
void solve(){
    int n,r;
    cin>>n>>r;
    set<int> s;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        s.insert(q);
    }
    vi a;
    for(int i:s){
        a.pb(i);
    }
    int count1=0;
    sort(a.begin(),a.end());
    int k1=a.size();
    for(int i=k1-1;i>=0;i--){
        a[i]=a[i]-r*count1;
        if(a[i]<=0){
            break;
        }
        else{
            count1++;
        }
    }
    cout<<count1<<"\n";
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }
}