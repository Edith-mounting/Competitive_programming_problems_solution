#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
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
        bool vis[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vis[i][j]=false;
            }
        }
        int a[r][c];
        int maxi=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
                maxi=max(maxi,a[i][j]);
            }
        }
        queue<pii> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==maxi){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        int count=0,i,j;
        while(!q.empty()){
            i=q.front().ff;
            j=q.front().ss;
            q.pop();
            if(a[i][j]<=1){
                continue;
            }
            if(i>0){
                if(!vis[i-1][j]){
                    count+=(a[i][j]-a[i-1][j]-1);
                    a[i-1][j]=a[i][j]-1;
                    q.push({i-1,j});
                    vis[i-1][j]=true;
                }
            }
            if(i<r-1){
                if(!vis[i+1][j]){
                    count+=(a[i][j]-a[i+1][j]-1);
                    a[i+1][j]=a[i][j]-1;
                    q.push({i+1,j});
                    vis[i+1][j]=true;
                }
            }
            if(j>0){
                if(!vis[i][j-1]){
                    count+=(a[i][j]-a[i][j-1]-1);
                    a[i][j-1]=a[i][j]-1;
                    q.push({i,j-1});
                    vis[i][j-1]=true;
                }
            }
            if(j<c-1){
                if(!vis[i][j+1]){
                    count+=(a[i][j]-a[i][j+1]-1);
                    a[i][j+1]=a[i][j]-1;
                    q.push({i,j+1});
                    vis[i][j+1]=true;
                }
            }
        }
        cout<<count<<"\n";
    }
}