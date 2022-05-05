#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue> 
#include <iomanip>
using namespace std;

const int PI=3.14159265358;
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
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}

int32_t main(){
    FIO;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    
    int gcd=__gcd(a[0],a[1]);
    for(int i=2;i<n;i++){
        gcd=__gcd(gcd,a[i]);
    }
    for(int i=0;i<n;i++){
        a[i]=a[i]/gcd;
    }
    map<int,int> mp;
    int N=1.5*(1e7) +5;
    int f[N];
    for(int i=1;i<N;i++){
        f[i]=i;
    }
    for(int i=2;i<N;i++){
        if(f[i]==i){
            for(int j=i*i;j<N;j+=i){
                f[j]=i;    
            }
        }
    }
    for(int i=0;i<n;i++){
        int k1=a[i];
        map<int,int> m;
        while(k1>1){
            m[f[k1]]++;
            k1/=f[k1];
        }
        for(auto j:m){
            mp[j.ff]++;
        }
    }
    int maxi=0;
    for(auto i:mp){
        maxi=max(maxi,i.ss);
    }
    if(maxi==0){
        cout<<-1;
    }
    else{
        cout<<n-maxi;
    }
    cout<<"\n";
}