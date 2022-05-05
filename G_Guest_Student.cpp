#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int k,n=7;
        cin>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int mini=inf;
        for(int i=0;i<n;i++){
            int count1=0;
            for(int j=i;j<n;j++){
                count1+=a[j];
            }
            for(int j=0;j<i;j++){
                count1+=a[j];
            }
            int kl=k/(count1);
            if(k%count1==0){
                kl=k/count1 -1;
            }
            int ans1=kl*7;
            int q=k%count1;
            if(k%count1==0){
                q=count1;
            }
            for(int j=i;j<n;j++){
                if(q>0){
                    q-=a[j];
                    ans1++;
                }
            }
            for(int j=0;j<i;j++){
                if(q>0){
                    q-=a[j];
                    ans1++;
                }
            }
            mini=min(mini,ans1);
        }
        cout<<mini<<"\n";
    } 
}