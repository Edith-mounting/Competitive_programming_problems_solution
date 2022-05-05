#include <iostream>
#include <algorithm>
#include <map>
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
int32_t main(){
    int n,q;
    cin>>n>>q;
    vi a(32,0);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a[log2(p)]++;
    }
    // for(int i=0;i<10;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    while(q--){
        int m;
        cin>>m;
        int count=0;
        for(int j=31;j>=0;j--){
            if(m==0){
                break;
            }
            if(a[j]>0){
                int x=m/powd(2,j);
                // count+=x;
                // m=m-x*a[j];
                if(x>a[j]){
                    count+=a[j];
                    m=m-a[j]*powd(2,j);
                }
                else{
                    count+=x;
                    m=m-x*powd(2,j);
                }
            }
        }
        if(m==0){
            cout<<count<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}