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
int absp(int k){
    if(k>0){
        return k;
    }
    else{
        return (-1)*k;
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        if(n%2==1){
            cout<<1;
        }
        else{
            sort(a,a+n);
            sort(b,b+n);
            int l=n/2,p=n/2 -1;
            int dis1=0,dis2=0,dis3=0,dis4=0;
            for(int i=0;i<n;i++){
                dis1+=absp(a[i]-a[l]);
                dis2+=absp(a[i]-a[p]);
            }
            for(int i=0;i<n;i++){
                dis3+=absp(b[i]-b[l]);
                dis4+=absp(b[i]-b[p]);
            }
            int count1=1,count2=1;
            //cout<<dis1<<" "<<dis2<<" ";
            if(dis1==dis2){
                count1=a[l]-a[p]+1;

            }
            if(dis3==dis4){
                count2=b[l]-b[p]+1;
            }
            cout<<count1*count2;
        }
        cout<<"\n";
    }
}