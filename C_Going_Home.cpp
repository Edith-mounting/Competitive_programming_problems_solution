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
bool f(int x1,int x2,int y1,int y2){
    if(x1==y1){
        return false;
    }
    if(x1==y2){
        return false;
    }
    if(x2==y1){
        return false;
    }
    if(x2==y2){
        return false;
    }
    return true;
    
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,vector<pii>> mp;
    bool bl=false;
    int x1,x2,y1,y2;
    int N=5*1000000+1;
    vector<pii> v(N,{0,0});
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=a[i]+a[j];
            int k1=v[sum].ff;
            int k2=v[sum].ss;
            if((k1==k2) && (k1==0)){
                v[sum]={i,j};
            }
            else{
                bl=f(i,j,k1,k2);
            }
            if(bl){
                x1=i,x2=j,y1=k1,y2=k2;
                break;
            }
        }
        if(bl){
            break;
        }
    }
    if(!bl){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
        cout<<x1+1<<" "<<x2+1<<" "<<y1+1<<" "<<y2+1<<"\n";
    }
}