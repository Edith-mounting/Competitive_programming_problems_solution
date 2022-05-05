#include<iostream>
#include <algorithm>
#include <vector>
#include <map>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int x=a[0],pl=1;
        for(int i=1;i<n;i++){
            if(x!=a[i]){
                pl++;
            }
        }
        if(pl==1){
            cout<<0;
        }
        else{
            map<int,int> mp;
            int k=a[0];
            mp[k]++;
            for(int i=1;i<n;i++){
                if(a[i]!=k){
                    k=a[i];
                    mp[k]++;
                }
            }
            int m=inf;
            for(auto i:mp){
                if(i.second>=2){
                    if(a[0]==i.first){
                        if(a[n-1]==i.first){
                            m=min(i.second-1,m);
                        }
                        else{
                            m=min(i.second,m);
                        }
                    }
                    else if(a[n-1]==i.first){
                        m=min(i.second,m);
                    }
                    else{
                        m=min(m,i.second+1);
                    }
                }
                else{
                    if(i.first==a[0] || i.first==a[n-1]){
                        m=1;
                    }
                    else{
                        m=min(i.second+1,m);
                    }
                }
            }
            cout<<m;
        }
        cout<<"\n";
    }
}