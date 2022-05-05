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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}

int32_t main()
{
	FIO;
    int n,k;
    cin>>n>>k;
    vi a(n+1,0);
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    map<int,bool> mp;
    for(int i=1;i<=n;i++){
        if(mp.find(b[i-1])==mp.end()){
            mp[b[i-1]]=true;
            a[i]=a[i-1]+1;
        }
        else{
            a[i]=a[i-1];
        }
    }
    for(int i=0;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    int i1=1;
    int maxi=1;
    for(int i2=2;i2<=n;i2++){
        if((a[i2]-a[i1-1])>k){
            while((a[i2]-a[i1-1])>k && i1<i2){
                i1++;
            }
        }
        else if((a[i2]-a[i1-1])==k){
            cout<<i1<<" "<<i2<<"\n";
            maxi=max(maxi,i2-i1+1);
        }
    }
    cout<<maxi<<"\n";
}