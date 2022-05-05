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

int32_t main() 
{
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans=0;
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            if(!v[i]){
                int a[26]={};
                for(int j=i;j<n;j+=k){
                    a[s[j]-'a']++;
                    v[j]=true;
                }
                //cout<<a[0]<<" "<<a[1]<<" ";
                for(int j=n-i-1;j>=0;j-=k){
                    if(!v[j]){
                        v[j]=true;
                        a[s[j]-'a']++;
                    }
                    else{
                        break;
                    }
                }
                int maxi=0;
                for(int j=0;j<26;j++){
                    /*if(a[j]>0){
                        cout<<a[j]<<" ";
                    }*/
                    maxi=max(maxi,a[j]);
                }
                for(int j=0;j<26;j++){
                    ans+=a[j];
                }
                ans-=maxi;
            }
        }
        cout<<ans<<"\n";
    }
}