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
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    int x=0;
    bool bl=true;
    vector<pii> ans(n+1,{0,0});
    for(auto i:mp){
        if(i.ff==0){
            if((n-i.ss)!=i.ff){
                bl=false;
                break;
            }   
        }
        else{
            if((n-i.ss)%i.ff!=0){
                bl=false;
                break;
            }
        }
    }
    if(!bl){
        cout<<"Impossible";
    }
    else{
        cout<<"Possible"<<"\n";
        if(a[0]==0){
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(ans[a[i]].ff==0){
                    x++;
                    ans[a[i]].ff++;
                    ans[a[i]].ss=x;
                }
            }
            for(int i=0;i<n;i++){
                int kl=ans[a[i]].ss;
                if(mp[a[i]]%ans[a[i]].ff==0 && ans[a[i]].ff>1){
                    kl+=ans[a[i]].ff/a[i] -1;
                }
                else{
                    kl+=ans[a[i]].ff/a[i];
                }
                //cout<<ans[a[i]].ff<<" ";
                ans[a[i]].ff++;
                cout<<kl<<" ";
            }
        }
    }
    cout<<"\n";
}