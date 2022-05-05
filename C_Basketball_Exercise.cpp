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
#define mod             998244353
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

int32_t main() {
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int ans=0;
    if(n==1){
        ans=max(a[0],b[0]);
    }
    else if(n==2){
        ans=max(a[0]+b[1],a[1]+b[0]);
    }
    else{
        int prev;
        int i;
        for(i=0;i<n-2;i++){
            if(i==0){
                if(a[0]+b[1]+a[2]>a[1]+b[0]+b[2]){
                    ans+=a[0];
                    prev=-1;
                }
                else{
                    ans+=b[0];
                    prev=1;
                }
            }
            else{
                if(prev==-1){
                    if(b[i]+a[i+1]+b[i+2]>b[i+1]+a[i+2]){
                        ans+=b[i];
                    }
                    else{
                        ans+=b[i+1];
                        i++;
                    }
                    prev=1;
                }
                else{
                    if(a[i]+b[i+1]+a[i+2]>a[i+1]+b[i+2]){
                        ans+=a[i];
                    }
                    else{
                        ans+=a[i+1];
                        i++;
                    }
                    prev=-1;
                }
            }
            //cout<<ans<<" ";
        }
        if(i==n-2){
            if(prev==-1){
                if(b[n-2]+a[n-1]>b[n-1]){
                    ans+=b[n-2]+a[n-1];
                }
                else{
                    ans+=b[n-1];
                }
            }
            else{
                if(a[n-2]+b[n-1]>a[n-1]){
                    ans+=a[n-2]+b[n-1];
                }
                else{
                    ans+=a[n-1];
                }
            }
        }
        else{
            if(prev==-1){
                ans+=b[n-1];
            }
            else{
                ans+=a[n-1];
            }
        }
    }
    cout<<ans<<"\n";
}