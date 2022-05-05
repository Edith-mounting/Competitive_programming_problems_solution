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

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=0;
            if(i==n-1){
                v[i][j]=1;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<=a[i+1][j]){
                v[i][j]=1;
            }
        }
    }
    int sum[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i][j]=0;
            if(i==0){
                sum[i][j]=v[i][j];
            }
        }
        
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i][j]=sum[i-1][j]+v[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(l==r){
            cout<<"Yes";
        }
        else if(l==0){
            r--;
            bool bl=false;
            for(int i=0;i<m;i++){
                if(sum[r][i]==r+1){
                    bl=true;
                    break;
                }
            }
            if(bl){
                cout<<"Yes";
            }
            else{
                cout<<"No";
            }
        }
        else{
            r--;
            bool bl=false;
            for(int i=0;i<m;i++){
                if(sum[r][i]-sum[l-1][i]==r-l+1){
                    bl=true;
                    break;
                }
            }
            if(bl){
                cout<<"Yes";
            }
            else{
                cout<<"No";
            }
        }
        cout<<"\n";
    }
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
	}
}
