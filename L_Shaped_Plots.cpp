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
        int r,c;
        cin>>r>>c;
        int a[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        int left[r][c];
        int right[r][c];
        int up[r][c];
        int down[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                left[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                right[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                up[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                down[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    if(j-1>=0){
                        if(a[i][j-1]==1){
                            left[i][j]=left[i][j-1]+1;
                        }
                        else{
                            left[i][j]=1;
                        }
                    }
                    else{
                        left[i][j]=1;
                    }
                    if(i-1>=0){
                        if(a[i-1][j]==1){
                            up[i][j]=up[i-1][j]+1;
                        }
                        else{
                            up[i][j]=1;
                        }
                    }
                    else{
                        up[i][j]=1;
                    }
                }
            }
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(a[i][j]==1){
                    if(j+1<c){
                        if(a[i][j+1]==1){
                            right[i][j]=right[i][j+1]+1;
                        }
                        else{
                            right[i][j]=1;
                        }
                    }
                    else{
                        right[i][j]=1;
                    }
                    if(i+1<r){
                        if(a[i+1][j]==1){
                            down[i][j]=down[i+1][j]+1;
                        }
                        else{
                            down[i][j]=1;
                        }
                    }
                    else{
                        down[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(up[i][j]>=2 && left[i][j]>=2){
                    int k1=max(up[i][j],left[i][j]);
                    int k2=min(up[i][j],left[i][j]);
                    ans+=min(k1/2,k2)-1;
                    ans+=k2/2 -1;
                }
                if(up[i][j]>=2 && right[i][j]>=2){
                    int k1=max(up[i][j],right[i][j]);
                    int k2=min(up[i][j],right[i][j]);
                    ans+=min(k1/2,k2)-1;
                    ans+=k2/2 -1;
                }
                if(down[i][j]>=2 && left[i][j]>=2){
                    int k1=max(down[i][j],left[i][j]);
                    int k2=min(down[i][j],left[i][j]);
                    ans+=min(k1/2,k2)-1;
                    ans+=k2/2 -1;
                }
                if(down[i][j]>=2 && right[i][j]>=2){
                    int k1=max(down[i][j],right[i][j]);
                    int k2=min(down[i][j],right[i][j]);
                    ans+=min(k1/2,k2)-1;
                    ans+=k2/2 -1;
                }
            }
        }
        cout<<ans<<"\n";
    }
}