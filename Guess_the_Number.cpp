
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
int N=1000000+1;
vi spf;
int32_t main() {
    spf.resize(N);
    spf[1] = 1; 
    for (int i=2; i<N; i++)  
        spf[i] = i; 

    for (int i=4; i<N; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<N; i++) 
    {  
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<N; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        }
    }
    vector<bool> ans(N,false);
    ans[1]=true;
    for(int i=2;i<N;i++){
        map<int,int> mp;
        int kl=i;
        while(kl!=1){
            mp[spf[kl]]++;
            kl/=spf[kl];
        }
        if(i==2){
            for(auto j:mp){
                cout<<j.ff<<" "<<j.ss<<" ";
            }
        }
        bool bl=true;
        for(auto j:mp){
            if((j.ss%2) ==1){
                bl=false;
            }
        }
        if(bl){
            ans[i]=true;
        }
    }
    vi ans1;
    for(int i=1;i<N;i++){
        if(ans[i]){
            ans1.pb(i);
        }
    }
    int w;
    cin>>w;
    while(w--){
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i]<<endl;
            cout<<endl;
            int kl;
            cin>>kl;
            if(kl==1){
                break;
            }
        }
        cout<<endl;
    }
}