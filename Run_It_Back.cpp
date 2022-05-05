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
struct help
{
    /* data */
    int x1,y1;
    char g;
};

int x,y;
bool comp(help a,help b){
    return ((a.x1-x)*(a.x1-x)+(a.y1-y)*(a.y1-y))<((b.x1-x)*(b.x1-x)+(b.y1-y)*(b.y1-y));
}
void solve(){
    cin>>x>>y;
    int n,k;
    cin>>n>>k;
    vector<help> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x1>>v[i].y1>>v[i].g;
    }
    sort(v.begin(),v.end(),comp);
    int c1=0,c2=0;
    for(int i=0;i<k;i++){
        if(v[i].g=='S'){
            c1++;
        }
        else{
            c2++;
        }
    }
    if(c1<=c2){
        cout<<"EASY AS CAKE";
    }
    else{
        cout<<"IT IS EXHILARATING";
    }
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}
}
