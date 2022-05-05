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
string solve(){
    string a,b;
    cin>>a>>b;
    int x1=0;
    for(int i=0;i<a.length();i++){
        x1+=a[i]-'0';
    }
    int x2=0;
    for(int i=0;i<b.length();i++){
        x2+=b[i]-'0';
    }
    if(x1>=x2){
        return "YES";
    }
    else{
        if(x1== x2-1){
            if(x1%2 ==1){
                return "YES";
            }
        }
        return "NO";
    }
}
int32_t main(){
    FIO;
    int w=1;
    //cin>>w;
    while(w--){
        cout<<solve()<<"\n";
    }
}