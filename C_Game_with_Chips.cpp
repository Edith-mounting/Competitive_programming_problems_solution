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
    int n,m,k;
    cin>>n>>m>>k;
    string s="";
    for(int i=0;i<2*k;i++){
        int a,b;
        cin>>a>>b;
    }
    for(int i=0;i<n-1;i++){
        s+='U';
    }
    for(int i=0;i<m-1;i++){
        s+='L';
    }
    string kl="";
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(i%2==0){
                kl+='R';
            }
            else{
                kl+='L';
            }
        }
        kl+='D';
    }
    for(int i=0;i<kl.length()-1;i++){
        s+=kl[i];
    }
    cout<<s.length()<<"\n";
    cout<<s<<"\n";
}