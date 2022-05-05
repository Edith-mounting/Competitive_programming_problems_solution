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
    int N=10000000+1;
    vi prime(N,0);
    prime[1] = 1; 
    for (int i=2; i<N; i++) 
        prime[i] = i; 
   
    for (int i=4; i<N; i+=2) 
        prime[i] = 2; 
  
    for (int i=3; i*i<N; i++) 
    { 
        if (prime[i] == i) 
        {  
            for (int j=i*i; j<N; j+=i) 
                if (prime[j]==j) 
                    prime[j] = i; 
        } 
    } 
    /*for(int i=1;i<=10;i++){
        cout<<prime[i]<<" ";
    }*/
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            map<int,int> mp;
            k=a[i];
            while(k!=1){
                mp[prime[k]]++;
                k/=prime[k];
            }
            for(auto i:mp){
                mp[i.ff]=mp[i.ff]%2;
            }
            int kl=1;
            for(auto i:mp){
                if(i.ss==1){
                    kl=kl*i.ff;
                }
            }
            a[i]=kl;
        }
        /*for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }*/
        int ans=0;
        map<int,bool> mp;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])!=mp.end()){
                ans++;
                mp.clear();
                mp[a[i]]=true;
            }
            else{
                mp[a[i]]=true;
            }
        }
        cout<<ans+1<<"\n";
    }
}