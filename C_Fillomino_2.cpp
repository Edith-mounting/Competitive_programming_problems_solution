#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
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
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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

int min(int x,int y,int z){
    return min(min(x,y),z);
}
struct hi{
    int k1,i1,j1;
};
bool com(hi a1,hi b1){
    return a1.k1<b1.k1;
}
int32_t main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;       
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i][i];
    }
    for(int i=0;i<n;i++){
        int value=a[i][i];
        int j1=i,i1=i;
        int k=a[i][i]-1;
        while(true){
            while(j1>0 && (a[i1][j1-1]==0) && k>0){
                a[i1][--j1]=value;
                k--;
            }
            if(k==0){
                break;
            }
            a[++i1][j1]=value;
            k--;
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}