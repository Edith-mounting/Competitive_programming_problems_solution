#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue> 
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int n;
vi a,b;
int32_t main(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int ans=0;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i:b){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n-1;i++){
        if(a[i]>b[i]){
            int l=i+1,r=n;
            int mid;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]+a[i]>b[mid]+b[i]){
                    l=mid+1;
                }
                else if(a[mid]+a[i]==b[mid]+b[i]){
                    break;
                }
                else{
                    r=mid-1;
                }
            }
            ans+=(mid-i-1);
            //cout<<(mid-1)
        }
    }
    /*if(a[n-1]>b[n-1]){
        ans++;
    }*/
    cout<<ans<<"\n";
}