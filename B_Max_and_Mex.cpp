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
    while (w--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        bool bl=true;
        int kl=0;
        for(int i=0;i<n;i++){
            if(a[i]!=i){
                kl=i;
                bl=false;
                break;
            }
        }
        if(bl){
            kl=n;
        }
        if(k==0){
            cout<<n;
        }
        else{
            if(kl==n){
                cout<<n+k;
            }
            else{
                int sum=(kl+a[n-1]+1)/2;
                bool bll=true;
                for(int i=0;i<n;i++){
                    if(a[i]==sum){
                        bll=false;
                        break;
                    }
                }
                if(!bll){
                    cout<<n;
                }
                else{
                    cout<<n+1;
                }
            }
        }
        cout<<"\n";
    }
}