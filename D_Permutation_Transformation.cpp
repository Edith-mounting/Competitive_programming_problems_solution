#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
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
int counti;
vi v;
void f(int x,int y,int a[]){
    int maxi=0,index;
    for(int i=x;i<y;i++){
        if(a[i]>maxi){
            maxi=a[i];
            index=i;
        }
    }
    if(maxi!=0){
        //cout<<index<<" ";
        if(x!=index){
            for(int i=x;i<index;i++){
                //cout<<"YES ";
                v[i]++;
            }
            f(x,index,a);
        }
        if(index+1<y){
            for(int i=index+1;i<y;i++){
                //cout<<"NO ";
                v[i]++;
            }
            f(index+1,y,a);
        }
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        counti=0;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        v.resize(n);
        for(int i=0;i<n;i++){
            v[i]=0;
        }
        f(0,n,a);
        //cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}