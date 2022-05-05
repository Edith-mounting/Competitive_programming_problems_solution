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
        int n,e,h,a,b,c;
        cin>>n>>e>>h>>a>>b>>c;
        int ans=-1;
        int x,y;
        for(int z=0;z<=n;z++){
            if(a<=b){
                x=(e-z)/2;
                y=n-x-z;
                if((e>=z) && (y <= (h-z)/3)){
                    //cout<<z<<" ";
                    if(ans==-1){
                        ans=a*x+b*y+c*z;
                    }
                    else{
                        ans=min(ans,a*x+b*y+c*z);
                    }
                }
            }
            else if(a>b){
                y=(h-z)/3;
                x=n-y-z;
                if((h>=z) && (x <= (e-z)/2)){
                    if(ans==-1){
                        ans=a*x+b*y+c*z;
                    }
                    else{
                        ans=min(ans,a*x+b*y+c*z);
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
        //cout<<"\n";
    }
}