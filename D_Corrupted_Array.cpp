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
        int m=n+2;
        int b[m];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b,b+m);
        bool bl=false;
        int x1=b[m-1],x2=b[m-2];
        int sum1=0,sum2=0;
        for(int i=0;i<m-1;i++){
            sum1+=b[i];
        }
        for(int i=0;i<m;i++){
            if(i!=(m-2)){
                sum2+=b[i];
            }
        }
        int x=-1;
        for(int i=0;i<m-1;i++){
            if((sum1-b[i])==x1){
                bl=true;
                x=i;
            }
        }
        if(bl){
            for(int i=0;i<m-1;i++){
                if(i!=x){
                    cout<<b[i]<<" ";
                }
            }
            cout<<"\n";
            continue;
        }
        for(int i=0;i<m;i++){
            if(i!=(m-2)){
                if((sum2-b[i])==x2){
                    bl=true;
                    x=i;
                }
            }
        }
        if(bl){
            for(int i=0;i<m;i++){
                if(i!=(m-2)){
                    if(i!=x){
                        cout<<b[i]<<" ";
                    }
                }
            }
            cout<<"\n";
            continue;
        }
        else{
            cout<<-1<<"\n";
        }
    }
}