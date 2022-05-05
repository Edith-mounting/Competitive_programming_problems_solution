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
    int n,m;
    cin>>n>>m;
    vi v;
    if(n<m){
        for(int i=1;i<=m;i++){
            v.pb(i);
        }
    }
    else{
        for(int i=0;i<m;i++){
            v.pb(i);
        }
    }
    int ans=0;
    int k1=v.size();
    for(int i=0;i<k1;i++){  
        for(int j=i;j<k1;j++){
            int q=((v[i]*v[i])%m +(v[j]*v[j])%m)%m;
            if(q==0){
                if(v[i]==v[j]){
                    int ql=n/m;
                    if(v[i]!=0){
                        if(v[i]<=n%m){
                            ql++;
                        }
                    }
                    ans+=(ql)*(ql);
                }
                else{
                    int ql=n/m;
                    int a=ql,b=ql;
                    if(v[i]!=0){
                        if(v[i]<=n%m){
                            a++;
                        }
                    }
                    if(v[j]!=0){
                        if(v[j]<=n%m){
                            b++;
                        }
                    }
                    ans+=2*a*b;    
                }
            }
            //cout<<v[i]<<" "<<v[j]<<" "<<ans<<"\n";
        }
        //cout<<ans<<" ";
    }
    cout<<ans<<"\n";
}