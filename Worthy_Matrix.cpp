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
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int kl;
                cin>>kl;
                a[i][j]=kl-k;
            }
        }
        int sum[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    if(j==0){
                        sum[i][j]=a[i][j];
                    }
                    else{
                        sum[i][j]=sum[i][j-1]+a[i][j];
                    }
                }
                else if(j==0){
                    sum[i][j]=sum[i-1][j]+a[i][j];
                }
                else{
                    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                /*if(a[i][j]>=0){
                    //cout<<i<<" "<<j<<" ";
                    int kl=min(n-i,m-j);
                    ans+=kl;
                    //cout<<kl<<"\n";
                    continue;
                }
                int q;
                for(int k=1;k<n;k++){
                    if(k+j>=m){
                        break;
                    }
                    if(k+i>=n){
                        break;
                    }
                    q=0;
                    q+=sum[i+k][k+j];
                    if(i==0){
                        if(j==0){
                            q-=0;
                        }
                        else{
                            q-=sum[i+k][j-1];
                        }
                    }
                    else if(j==0){
                        q-=sum[i-1][j+k];
                    }
                    else{
                        q+=sum[i-1][j-1]-sum[i-1][j+k]-sum[i+k][j-1];
                    }
                    if(q>=0){
                        //cout<<"YES ";
                        int kl=min(n-k-i,m-k-j);
                        //cout<<i<<" "<<j<<" ";
                        ans+=kl;
                        //cout<<kl<<"\n";
                        break;
                    }
                }*/
                int kl=min(n-i,m-j);
                if(a[i][j]>=0){
                    ans+=kl;
                    continue;
                }
                else{
                    int l=0,r=kl-1,mid=0,res=-1,k;
                    while(l<=r){
                        k=(r+l)/2;
                        int q=0;
                        q+=sum[i+k][k+j];
                        if(i==0){
                            if(j==0){
                                q-=0;
                            }
                            else{
                                q-=sum[i+k][j-1];
                            }
                        }
                        else if(j==0){
                            q-=sum[i-1][j+k];
                        }
                        else{
                            q+=sum[i-1][j-1]-sum[i-1][j+k]-sum[i+k][j-1];
                        }
                        if(q>=0){
                            res=k;
                            r=k-1;
                        }
                        else{
                            l=k+1;
                        }
                    }
                    if(res>=0){
                        ans+=kl-res;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}