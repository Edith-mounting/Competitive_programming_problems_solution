#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
int32_t main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n;
        k=n;
        vi v;
        while(k>0){
            v.pb(k%2);
            k=k/2;
        }
        reverse(v.begin(),v.end());
        
        k=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                k++;
            }
        }
        if(k==0){
            int div=1;
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    div=max(div,max(n/i,i));
                }
            }
            cout<<div;
        }
        else{
            int k=1;
            for(int i=0;i<v.size();i++){
                k=k*2;
            }
            cout<<k-1;
        }
        cout<<"\n";
    }
}