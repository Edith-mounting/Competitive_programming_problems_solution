#include <iostream>
#include <algorithm>
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
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return ((t*t)%mod*x)%mod;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi best(n,inf);
    int i1=-1;//nearest train going in right direction
    best[0]=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            best[i]=0;
        }
        if(i1==-1){
            if(a[i]==1){
                i1=i;
            }
        }
    }
    int alpha;
    if(i1!=-1){
        alpha=i1;
        for(int i=alpha+1;i<n;i++){
            if(a[i]==1){
                i1=i;
            }
            else if(a[i]==0){
                best[i]=min(best[i],i-i1);
            }
        }
    }
    int i2=-1;
    for(int i=n-1;i>=0;i--){
        if(a[i]==2){
            i2=i;
            break;
        }
    }
    if(i2!=-1){
        alpha=i2;
        for(int i=alpha-1;i>=0;i--){
            if(a[i]==2){
                i2=i;
            }
            else if(a[i]==0){
                best[i]=min(best[i],i2-i);
            }
        }
    }
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        if(best[k-1]==inf){
            cout<<-1;
        }
        else{
            cout<<best[k-1];
        }
        cout<<" ";
    }
}
int32_t main()
{
	FIO;
	int w=1;
	cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}
}
