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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
struct help{
    int x1,y1,i1;
};
bool f(char a,char a1,char a2 ,char a3,char a4){
    if(a=='*' && a1=='*' && a2=='*' && a3=='*' && a4=='*'){
        return true;
    }
    return false;
}
int32_t main()
{
	FIO;
	int w=1;
	cin>>w;
	while(w--){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(a!=b){
            int p=a*a-b*b;
            int ans;
            int k1=(a*x-b*y)/p;
            int k2=(a*y-b*x)/p;
            if(k1<0 || k2<0){
                if(k1<0){
                    ans=min(x/b,y/a);
                }
                else{
                    ans=min(x/a,y/b);
                }
                cout<<ans<<"\n";
                continue;
            }
            ans=min(x/b,y/a);
            ans=max(ans,min(x/a,y/b));
            int q=k1+k2;
            if((a*(k1+1)+b*k2<=x) && (a*k2+b*(k1+1)<=y)){
                ans=max(ans,q+1);
            }
            else if(a*(k1)+b*(k2+1)<=x && (a*(k2+1)+ b*(k1)<=y)){
                ans=max(ans,q+1);
            }
            ans=max(ans,k1+k2);
            cout<<ans<<"\n";
        }
        else{
            int ans;
            ans=min(x/a,y/a);
            cout<<ans<<"\n";
        }
	}
}
