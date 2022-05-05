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
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int x=0,y=0;
    bool b=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int p[8]={1,0,-1,0,-1,1,-1,1};//for row
    int q[8]={0,1,0,-1,-1,-1,1,1};//for col
    int counti=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='A'){
                char k='A';
                int count=1;
                int x=i,y=j;
                while(count<26){
                    int x1=x,y1=y;
                    for(int i=0;i<8;i++){
                        x1+=p[i];
                        y1+=q[i];
                        if(x1<0 || x1>=n)continue;
                        if(y1<0 || y1>=m)continue;

                        if(a[x1][y1]==(char)((int)k+1)){
                            count++;
                        }
                    }
                }
            }
        }
    }
    
}