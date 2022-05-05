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
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        vi sum;
        for(int i=0;i<n/2;i++){
            sum.pb(a[i]+a[n-i-1]);
        }
        sort(sum.begin(),sum.end());
        int kl=sum.size();
        int sum1,sum2;
        if(kl%2==0){
            sum1=sum[kl/2];
            sum2=sum[kl/2 -1];
        }
        else{
            sum1=sum[kl/2];
            sum2=sum[kl/2];
        }
        int ans1=0,ans2=0;
        int c,d;
        cout<<sum1<<" "<<sum2<<" ";
        for(int i=0;i<n/2;i++){
            c=max(a[i],a[n-i-1]);
            d=min(a[i],a[n-i-1]);
            if(c+d>sum1){
                if(d>sum1){
                    ans1+=2;
                }
                else{
                    ans1++;
                }
            }
            else if(c+d<sum1){
                if(sum1-d>k){
                    ans1+=2;
                }
                else{
                    ans1++;
                }
            }
            if(c+d>sum2){
                if(d>sum2){
                    ans2+=2;
                }
                else{
                    ans2++;
                }
            }
            else if(c+d<sum2){
                if(sum2-d>k){
                    ans2+=2;
                }
                else{
                    ans2++;
                }
            }
        }
        cout<<min(ans1,ans2)<<"\n";
    }
}