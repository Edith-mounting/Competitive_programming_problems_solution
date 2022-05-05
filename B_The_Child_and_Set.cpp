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
    int n=100000+2;
    vi v(n,0);
    v[1]=1;
    for(int i=2;i<n;i++){
        int k=i;
        int counti=0;
        while(k%2==0){
            counti++;
            k/=2;
        }
        v[i]=v[i-1]+pow(2,counti);
    }
    int sum,limit;
    cin>>sum>>limit;
    if(sum<=v[limit]){
        set<int> s;
        int i=limit;
        while(i>0){
            int k=i;
            int counti=0;
            while(k%2==0){
                counti++;
                k/=2;
            }
            if(pow(2,counti)<=sum){
                sum-=pow(2,counti);
                s.insert(i);
            }
            i--;
        }
        cout<<s.size()<<"\n";
        for(auto i:s){
            cout<<i<<" ";
        }
    }
    else{
        cout<<-1;
    }
    cout<<"\n";
}