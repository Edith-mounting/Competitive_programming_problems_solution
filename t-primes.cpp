#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
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
int binarysearch(int n){
    int start=1,end=n;
    int mid,ans;
    while(start<=end){
        mid=start+ (end-start)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int N=1000005;
    vector<bool> v(N,true);
    v[0]=false;
    v[1]=false;
    for(int i=2;i<N;i++){
        if(v[i]){
            for(int j=i*2;j<N;j+=i){
                v[j]=false;
            }
        }
    }
    vector<string> v1;
    for(int i=0;i<n;i++){
        int x=sqrt(a[i]);
        //cout<<x<<" ";
        if(x*x==a[i]){
            if(v[x]){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}
int32_t main()
{
    int w=1;
    while(w--){
        solve();
    }
}