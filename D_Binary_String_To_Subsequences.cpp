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

int32_t main() 
{
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<bool> vl(n);
        vector<int> v;
        if(s[0]=='1'){
            vl[1]=true;
        }
        else{
            vl[1]=false;
        }
        v.pb(1);
        int prev=1;
        int maxi=1;
        for(int i=0;i<n;i++){
            if(prev<=maxi){
                if(vl[prev]){
                    if(s[i]=='1'){
                        
                    }
                    else{

                    }
                }
            }
        }
        
        cout<<maxi<<"\n";
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}