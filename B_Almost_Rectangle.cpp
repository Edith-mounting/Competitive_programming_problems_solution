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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        char a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int x1,y1,x2,y2;
        int count=0;
        bool b=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(count==0 && a[i][j]=='*'){
                    x1=i,y1=j;
                    count++;
                }
                else if(count==1 && a[i][j]=='*'){
                    count++;
                    x2=i,y2=j;
                    b=true;
                    break;
                }
            }
            if(b){
                break;
            }
        }
        if(x1==x2){
            if(x1==0){
                a[x1+1][y1]='*';
                a[x1+1][y2]='*';
            }
            else{
                a[x1-1][y1]='*';
                a[x1-1][y2]='*';
            }
        }
        else{
            if(y1==y2){
                if(y1==0){
                    a[x1][y1+1]='*';
                    a[x2][y1+1]='*';
                }
                else{
                    a[x1][y1-1]='*';
                    a[x2][y1-1]='*';
                }
            }
            else{
                a[x1][y2]='*';
                a[x2][y1]='*';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
}