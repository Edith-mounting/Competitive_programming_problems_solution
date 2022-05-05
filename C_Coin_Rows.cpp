#include <iostream>
#include <algorithm>
#include <map>
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return powd(x,y/2)*powd(x,y/2);
    }
    else{
        int t=powd(x,y/2);
        return (x*t*t);
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int m;
        cin>>m;
        int a[2][m];
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        if(m==1){
            cout<<0<<"\n";
            continue;
        }
        int sum[2][m];
        sum[1][0]=a[1][0];
        sum[0][m-1]=a[0][m-1];
        for(int i=1;i<m;i++){
            sum[1][i]=sum[1][i-1]+a[1][i];
        }
        for(int i=m-2;i>=0;i--){
            sum[0][i]=sum[0][i+1]+a[0][i];
        }
        int ans=inf;
        for(int i=0;i<m;i++){
            if(i==0){
                ans=min(ans,sum[0][i+1]);
            }
            else if(i==m-1){
                ans=min(ans,sum[1][i-1]);
            }
            else{
                ans=min(ans,max(sum[0][i+1],sum[1][i-1]));
            }
        }
        cout<<ans<<"\n";
    }
}