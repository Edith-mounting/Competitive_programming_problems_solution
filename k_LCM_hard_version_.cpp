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
        int a,b,c;
        n=n-(k-3);
        if(n%2==1){
            c=1;
            a=(n-1)/2;
            b=(n-1)/2;
        }
        else if(n%3==0){
            a=n/3;
            b=n/3;
            c=n/3;
        }
        else{
            if(n%4==0){
                a=(n)/4;
                b=(n)/4;
                c=n/2;
            }
            else{
                a=(n-2)/2;
                b=(n-2)/2;
                c=2;
            }
        }
        cout<<a<<' '<<b<<" "<<c<<" ";
        for(int i=0;i<k-3;i++){
            cout<<1<<" ";
        }
        cout<<"\n";
    }
}