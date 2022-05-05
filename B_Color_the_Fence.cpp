#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int v;
    cin>>v;
    int a[9];
    for(int i=0;i<9;i++)cin>>a[i];
    int x=inf;
    int p;
    for(int i=0;i<9;i++){
        if(a[i]<=x){
            x=a[i];
            p=i+1;
        }
    }
    if(x>v){
        cout<<-1;
    }
    else{
        vi klm;
        int d=v/x;
        int m=v%x +x;
        bool b=true;
        while(b){
            b=false;
            int k,xl;
            for(int i=p;i<9;i++){
                if(a[i]<=m){
                    k=a[i];
                    xl=i+1;
                    b=true;
                }
            }
            if(b){
                klm.pb(xl);
                d--;
                if(d>0){
                    m=m%k+x;
                }
                else{
                    break;
                }
            }
        }
        sort(klm.begin(),klm.end());
        reverse(klm.begin(),klm.end());
        for(auto i:klm){
            cout<<i;
        }
        for(int i=0;i<d;i++){
            cout<<p;
        }
        
    }
    cout<<"\n";
}