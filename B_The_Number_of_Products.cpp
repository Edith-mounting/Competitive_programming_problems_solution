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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    vi v;
    v.pb(-1);
    for(int i=0;i<n;i++){
        if(a[i]<0){
            v.pb(i);
        }
    }
    v.pb(n);
    if(v.size()>2){
        vi k;
        for(int i=1;i<v.size();i++){
            k.pb(v[i]-v[i-1]-1);
        }
        int q=v.size()-1;
        vi sum(q);
        sum[0]=k[0];
        sum[1]=k[1];
        for(int i=2;i<q;i++){
            sum[i]=sum[i-2]+k[i];
        }
        for(int i=0;i<q;i++){
            int p=(q-1)-(1-(q-1)%2);
            int l=q-1;
            if(q%2==0){
                l=q-2;
            }
            int x=sum[p];
            int y=sum[l];
            if(i==0){
                ans+=x*(1+k[i])+((p-i-1)/2 +1)*(1+k[i]);
            }
            else if(i==1){
                ans+=y*(1+k[i])+ ((l-i+1)/2)*(1+k[i]);
            }
            else{
                if(i%2==0){
                    x=x-sum[p-2];
                    ans+=x*(1+k[i])+((p-i-1)/2 +1)*(1+k[i]);
                }
                else{
                    y=y-sum[l-2];
                    cout<<y<<"\n";
                    ans+=y*(1+k[i])+ ((l-i+1)/2)*(1+k[i]);
                }
                cout<<ans<<" ";
            }
        }
    }
    cout<<ans<<" "<<(n*(n+1))/2 -ans<<"\n";
}