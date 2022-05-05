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
        int c[10];
        for(int i=0;i<10;i++){
            cin>>c[i];
        }
        int mini=inf,index;
        for(int i=0;i<10;i++){
            if(c[i]<=mini){
                mini=c[i];
                index=i;
            }
        }
        if(index==0){
            cout<<1;
            for(int i=0;i<mini+1;i++){
                cout<<0;
            }
        }
        else{
            for(int i=1;i<10;i++){
                if(c[i]==mini){
                    index=i;
                    break;
                }         
            }
            for(int i=0;i<mini+1;i++){
                cout<<index;
            }
        }
        cout<<"\n";
    }
}