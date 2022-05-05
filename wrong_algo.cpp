#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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
#define pqs             priority_queue<int,vi,greater<int> >//for min-heap in cpp
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000007
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
    int n;
    cin>>n;
    if(n<=5){
        cout<<-1<<"\n";
    }
    else if(n==6){
        cout<<1<<" "<<2<<"\n";
        cout<<1<<" "<<3<<"\n";
        cout<<1<<" "<<4<<"\n";
        cout<<2<<" "<<5<<"\n";
        cout<<2<<" "<<6<<"\n";
    }
    else if(n==7){
        cout<<1<<" "<<2<<"\n";
        cout<<1<<" "<<3<<"\n";
        cout<<1<<" "<<4<<"\n";
        cout<<2<<" "<<5<<"\n";
        cout<<2<<" "<<6<<"\n";
        cout<<2<<" "<<7<<"\n";
    }
    else{
        int m=n-7;
        cout<<1<<" "<<2<<"\n";
        cout<<1<<" "<<3<<"\n";
        cout<<2<<" "<<4<<"\n";
        cout<<3<<" "<<6<<"\n";
        cout<<3<<" "<<7<<"\n";
        cout<<6<<" "<<5<<"\n";
        while(m>0){
            cout<<6<<" "<<m+7<<"\n";
            m--;
        }
    }
    for(int i=2;i<n+1;i++){
        cout<<1<<" "<<i<<"\n";
    }
}