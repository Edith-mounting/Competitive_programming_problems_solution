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
bool comp(help x,help y){
    if(x.i1!=y.i1){
        return x.i1<y.i1;
    }
    else{
        if(x.x1!=y.x1){
            return x.x1<y.x1;
        }
        else{
            return x.y1<y.y1;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    int maxi=0,mini=inf;
    int i1,i2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxi){
            maxi=a[i];
            i1=i;
        }
        if(a[i]<mini){
            mini=a[i];
            i2=i;
        }
    }
    int ans=inf;
    ans=min(ans,max(i1,i2)+1);
    ans=min(ans,n-min(i1,i2));
    ans=min(ans,i1+1+n-i2);
    ans=min(ans,i2+1+n-i1);
    cout<<ans;
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
