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

int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"YES\n";
    int gd=a[0];
    for(int i=1;i<n;i++){
        gd=gcd(gd,a[i]);
    }
    if(gd>1){
        cout<<0;
    }
    else{
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
                if(i==n-1){
                    count+=2;
                }
                else{
                    count++;
                    int c=a[i];
                    a[i]=a[i]-a[i+1];
                    a[i+1]=c+a[i+1];
                    if(a[i]%2 !=0){
                        count++;
                        c=a[i];
                        a[i]=a[i]-a[i+1];
                        a[i+1]=c+a[i+1];
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    cout<<"\n";
}