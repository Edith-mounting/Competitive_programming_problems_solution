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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int r,c;
    cin>>r>>c;
    if(r==1 && c==1){
        cout<<0;
    }
    else{
        int x=max(r,c);
        int y=min(r,c);
        int a[y][x];
        for(int i=0;i<x;i++){
            a[0][i]=i+2;
        }
        for(int i=1;i<y;i++){
            for(int j=0;j<x;j++){
                a[i][j]=(x+1+i)*a[0][j];
            }
        }
        if(r>c){
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    cout<<a[j][i]<<" ";
                }
                cout<<"\n";
            }
        }
        else{
            for(int i=0;i<y;i++){
                for(int j=0;j<x;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    }
}