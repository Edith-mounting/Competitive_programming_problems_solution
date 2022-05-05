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
int32_t main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int counti=0;
    for(int i=0;i<k1;i++){
        int maxi=absk(a[0]-b[0]),i1=0;
        for(int j=1;j<n;j++){
            if(absk(a[j]-b[j])>maxi){
                i1=j;
                maxi=absk(a[j]-b[j]);
            }
        }
        if(maxi==0){
            counti+=(k1-i);
            break;
        }
        else{
            if(a[i1]>b[i1]){
                a[i1]--;
            }
            else{
                a[i1]++;
            }
        }
    }
    for(int i=0;i<k2;i++){
        int maxi=absk(a[0]-b[0]),i1=0;
        for(int j=1;j<n;j++){
            if(absk(a[j]-b[j])>maxi){
                i1=j;
                maxi=absk(a[j]-b[j]);
            }
        }
        if(maxi==0){
            counti+=(k2-i);
            break;
        }
        else{
            if(b[i1]>a[i1]){
                b[i1]--;
            }
            else{
                b[i1]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(a[i]-b[i])*(a[i]-b[i]);
    }
    ans+=counti%2;
    cout<<ans<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<b[i]<<" ";
    // }

}