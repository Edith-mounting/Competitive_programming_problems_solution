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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int t;
    cin>>t;
    int a[31]={};
    a[0]=1;
    for(int i=1;i<31;i++){
        a[i]=2*a[i-1];
    }
    while(t--){
        int u,v;
        cin>>u>>v;
        if(u<=v){
            vi a(31,0),b(31,0);
            int i=0;
            while(u>0){
                a[i]=u%2;
                u/=2;
                i++;
            }
            i=0;
            while(v>0){
                b[i]=v%2;
                v/=2;
                i++;
            }
            bool bl=true;
            int count1=0,count2=0;
            for(i=0;i<31;i++){
                count1+=a[i];
                count2+=b[i];
                if(count2>count1){
                    bl=false;
                    break;
                }
            }
            if(!bl){
                cout<<"NO";
            }
            else{
                cout<<"YES";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}