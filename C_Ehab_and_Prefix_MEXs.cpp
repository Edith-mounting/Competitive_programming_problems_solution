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

int pro(int a[]){
    int k=1;
    for(int i=0;i<10;i++){
        k=k*a[i];
    }
    return k;
}
int32_t main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    bool bl=true;
    for(int i=0;i<n;i++){
        if(a[i]>i+1){
            bl=false;
            break;
        }
    }
    if(!bl){
        cout<<-1;
    }
    else{
        vector<bool> v(n+1,false);
        for(int i=0;i<n;i++){
            v[a[i]]=true;
        }
        vi vl;
        for(int i=0;i<n+1;i++){
            if(!v[i]){
                vl.pb(i);
            }
        }
        int k=0;
        int b[n]={};
        b[0]=vl[k];
        k++;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                b[i]=a[i-1];
            }
            else{
                b[i]=vl[k];
                k++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
    }
    cout<<"\n";
}