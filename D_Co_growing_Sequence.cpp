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
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int ans[n];
        ans[0]=0;
        for(int i=1;i<n;i++){
            int q=(a[i-1]^ans[i-1]);
            if((a[i]&q)!=q){
                int x=0;
                vi p(31,0),r(31,0);
                int m=a[i];
                int j=0;
                while(m>0){
                    p[j]=m%2;
                    m/=2;
                    j++;
                }
                
                j=0;
                while(q>0){
                    r[j]=q%2;
                    j++;
                    q/=2;
                }
                j=1;
                for(int i1=0;i1<31;i1++){
                    if(r[i1]==1 && p[i1]!=1){
                        x=x+j;
                    }
                    j=j*2;
                }
                ans[i]=x;
            }
            else{
                ans[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}