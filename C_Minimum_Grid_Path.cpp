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
int32_t main() 
{
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int ans1=inf,ans2=inf;
        int count=0;
        int x=0,y=0;
        int prev1=0,prev2=0;
        for(int i=0;i<n;i+=2){
            ans1=min(prev1+a[i]*(n- i/2),ans1);
            prev1+=a[i];
            x++;
        }
        for(int i=1;i<n;i+=2){
            ans2=min(prev2+a[i]*(n- i/2),ans2);
            prev1+=a[i];
            y++;
        }
        //cout<<ans1<<"\n";
        count=ans1+ans2;
        count=min(count,)
        cout<<count<<"\n";
    }
}