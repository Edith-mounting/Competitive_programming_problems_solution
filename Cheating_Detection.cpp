#include <iostream>
#include <algorithm>
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
int32_t main(){
    int w,wl;
    cin>>w;
    wl=w;
    int p;
    cin>>p;
    while(w--){
        cout<<"Case #"<<wl-w<<": ";
        char a[100][1000];
        vi sum(100,0);
        for(int i=0;i<100;i++){
            for(int j=0;j<1000;j++){
                cin>>a[i][j];
                sum[i]+=(a[i][j]-'0');
            }
        }
        sort(sum.begin(),sum.end());
        vector<int>::iterator low1;
        low1=lower_bound(sum.begin(),sum.end(),50);
        cout<<(low1-sum.begin()+1)<<"\n";
        
    }
}