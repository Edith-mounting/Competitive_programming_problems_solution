#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int32_t main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int mat[n][n];
    vi d1(2*n-1,0);
    vi d2(2*n-1,0);
    int index=0;
    int p,q;
    for(int i=n-1;i>=0;i--){
        p=i,q=0;
        while(true){
            d1[index]+=a[p][q];
            p++;
            q++;
            if(p<0 || q<0){
                break;
            }
            if(p>n-1 || q>n-1){
                break;
            }
        }
        index++;
    }
    for(int j=1;j<n;j++){
        p=0,q=j;
        while(true){
            d1[index]+=a[p][q];
            p++;
            q++;
            if(p<0 || q<0){
                break;
            }
            if(p>n-1 || q>n-1){
                break;
            }
        }
        index++;
    }
    index=0;
    for(int j=0;j<n;j++){
        p=0,q=j;
        while(true){
            d2[index]+=a[p][q];
            p++;
            q--;
            if(p<0 || q<0){
                break;
            }
            if(p>n-1 || q>n-1){
                break;
            }
        }
        index++;
    }
    for(int i=1;i<n;i++){
        p=i,q=n-1;
        while(true){
            d2[index]+=a[p][q];
            p++;
            q--;
            if(p<0 || q<0){
                break;
            }
            if(p>n-1 || q>n-1){
                break;
            }
        }
        index++;
    }
    reverse(d1.begin(),d1.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=d1[(i+n-j)-1]-a[i][j]+d2[i+j];
        }
    }
    int maxi1x,maxi2x,maxi1y,maxi2y,maxi1=0,maxi2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2 ==0){
                if(mat[i][j]>=maxi1){
                    maxi1=mat[i][j];
                    maxi1x=i;
                    maxi1y=j;
                }
            }
            else{
                if(mat[i][j]>=maxi2){
                    maxi2=mat[i][j];
                    maxi2x=i;
                    maxi2y=j;
                }
            }
        }
    }
    cout<<maxi1+maxi2<<"\n";
    cout<<maxi1x+1<<" "<<maxi1y+1<<" "<<maxi2x+1<<" "<<maxi2y+1<<"\n";
}