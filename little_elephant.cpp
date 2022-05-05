#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
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
#define mod             1000000007
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
    int a[4][4];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    a[3][3]=(2*a[3][1]+a[2][1]-a[2][3])/2;
    a[1][1]=a[3][1]+a[1][3]-a[3][3];
    a[2][2]=a[1][1]+a[1][2]+a[1][3]-a[2][1]-a[2][3];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
