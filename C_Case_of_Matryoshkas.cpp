#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() 
{   
    FIO;
    int n,k;
    cin>>n>>k;
    vi a[k];
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int q;
            cin>>q;
            a[i].pb(q);
        }
    }
    /*for(int i=0;i<k;i++){
        for(int j:a[i]){
            cout<<j<<" ";
        }
        cout<<<"\n";
    }*/
    int count=0;
    int ans=0;
    for(int i=0;i<k;i++){
        for(int j=1;j<a[i].size();j++){
            if(a[i][j]!=(a[i][j-1]+1)){
                count++;
                //ans+=;
            }
        }
        cout<<(count)<<"\n";
    }
    cout<<(count)<<"\n";
}