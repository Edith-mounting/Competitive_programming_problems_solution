#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
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
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
int32_t main(){
    FIO;
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n],b[n-1];
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s1+=a[i];
        }
        for(int i=0;i<n-1;i++){
            cin>>b[i];
            s2+=b[i];
        }
        sort(a,a+n);
        sort(b,b+n-1);
        int ans=0;
        if(n==2){
            ans=b[0]-a[0];
            if(a[1]<=b[0]){
                ans=b[0]-a[1];
            }
            cout<<ans<<"\n";
            continue;
        }
        else{
            //a[0] skip
            bool bl=true;
            int x1=b[0]-a[1];
            if(x1>0){
                for(int i=2;i<n;i++){
                    if(b[i-1]-a[i] != x1){
                        bl=false;
                        break;
                    }
                }
                if(bl){
                    ans=x1;
                    cout<<ans<<"\n";
                    continue;
                }
            }
            int x2=(b[0]-a[0]);
            for(int i=2;i<n;i++){
                if((b[i-1]-a[i])!=x2){
                    bl=false;
                    break;
                }
            }
            if(bl){
                ans=x2;
                cout<<ans<<"\n";
                continue;
            }
            cout<<(b[0]-a[0])<<"\n";
            continue;
        }
    }
}