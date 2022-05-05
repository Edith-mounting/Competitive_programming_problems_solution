#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
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

int min(int x,int y,int z){
    return min(min(x,y),z);
}
int32_t main()
{
    int n;
    cin>>n;
    if(n<=3){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
        if(n%2==0){
            int k=n-4;
            k/=2;
            for(int i=n;i>=6;i-=2){
                cout<<i<<" - "<<i-1<<" = "<<1<<"\n";
            }
            cout<<"4 * 3 = 12\n";
            cout<<"2 * 1 = 2\n";
            cout<<"12 * 2 = 24\n";
            for(int i=0;i<k;i++){
                cout<<24<<" * "<<1<<" = "<<24<<"\n";
            }
        }
        else{
            int k=n-5;
            k/=2;
            for(int i=n;i>=7;i-=2){
                cout<<i<<" - "<<i-1<<" = "<<1<<"\n";
            }
            cout<<"5 + 1 = 6\n";
            cout<<"3 - 2 = 1\n";
            cout<<"6 * 4 = 24\n";
            cout<<"24 * 1 = 24\n";
            for(int i=0;i<k;i++){
                cout<<24<<" * "<<1<<" = "<<24<<"\n";
            }
        }
    }
}