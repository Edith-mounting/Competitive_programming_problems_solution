
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
int32_t main() {
    int w,wl;
    cin>>w;
    wl=w;
    while(w--){
        cout<<"Case "<<"#"<<wl-w<<": ";
        int n;
        cin>>n;
        int a[n][n],b[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>b[i][j];
            }
        }
        int r[n],c[n];
        int ans=0;
        for(int i=0;i<n;i++)cin>>r[i];
        for(int i=0;i<n;i++)cin>>c[i];
        if(n==1){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==-1){
                    int k1=0;
                    for(int k=0;k<n;k++){
                        if(a[i][k]==-1){
                            k1++;
                        }
                    }
                    if(k1==1){
                        a[i][j]=0;
                    }
                    else{
                        k1=0;
                        for(int k=0;k<n;k++){
                            if(a[k][j]==-1){
                                k1++;
                            }
                        }
                        if(k1==1){
                            a[i][j]=0;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==-1){
                    int k1=0,k2=0;
                    for(int k=0;k<n;k++){
                        if(a[k][j]==-1){
                            k1++;
                        }
                    }
                    
                }
            }
        }
    }
}