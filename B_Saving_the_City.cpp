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
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int n=s.length();
        int ans=0;
        vector<pii> v;
        int l=-1,r=0;
        if(s[0]=='1'){
            l=0;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(l==-1){
                    l=i;
                }
            }
            else{
                if(s[i-1]=='1'){
                    r=i-1;
                    v.pb({l,r});
                    l=-1;
                }
            }
        }
        if(l!=-1){
            v.pb({l,n-1});
        }
        int k=v.size();
        vector<bool> vb(k,false);
        for(int i=0;i<k-1;i++){
            if(!vb[i]){
                int kl=b*(v[i+1].ff-v[i].ss-1);
                if(kl<=a){
                    ans+=(a+kl);
                    vb[i]=true;
                    vb[i+1]=true;
                }
                else{
                    ans+=(a);
                    vb[i]=true;
                }
            }
        }
        if(k>0 && !vb[k-1]){
            ans+=a;
        }
        cout<<ans<<"\n";
    }
}