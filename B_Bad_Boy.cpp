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
struct co{
    int x,y;
};
int f(int x1,int y1,int x2,int y2,int i,int j){
    int ans=absk(x1-i)+absk(y1-j)+absk(x2-x1)+absk(y2-y1)+absk(x2-i)+absk(y2-j);
    return ans;
}
void solve(){
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    i--,j--;
    co a,b;
    //(0,0)
    pii v[4];
    v[0].ff=0,v[0].ss=0;
    v[1].ff=0,v[1].ss=m-1;
    v[2].ff=n-1,v[2].ss=0;
    v[3].ff=n-1,v[3].ss=m-1;
    int ans=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=j){
                int k1=f(v[i].ff,v[i].ss,v[j].ff,v[j].ss,i,j);
                if(k1>ans){
                    ans=k1;
                    a.x=v[i].ff;
                    a.y=v[i].ss;
                    b.x=v[j].ff;
                    b.y=v[j].ss;
                }
            }
        }
    }
    cout<<a.x+1<<" "<<a.y+1<<" "<<b.x+1<<" "<<b.y+1<<"\n";
}
int32_t main()
{
	FIO;
	int w=1;
	cin>>w;
	while(w--){
		solve();
	}
}
