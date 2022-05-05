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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y&1){
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (t*t)%mod;
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        char s[9][9];
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>s[i][j];
            }
        }
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=(s[i][j]-'0');
            }
        }
        a[0][0]=(9-a[0][0]);
        a[1][3]=(9-a[1][3]);
        a[2][6]=(9-a[2][6]);
        a[3][7]=(9-a[3][7]);
        a[4][4]=(9-a[4][4]);
        a[5][1]=(9-a[5][1]);
        a[6][2]=(9-a[6][2]);
        a[7][5]=(9-a[7][5]);
        a[8][8]=(9-a[8][8]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    cout<<1;
                }
                else{
                    cout<<a[i][j];
                }
            }
            cout<<"\n";
        }
    }
}