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
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        char s[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>s[i][j];
            }
        }
        int a[n][n],b[n][n];//a->down_top//b->right_left
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=0;
                b[i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                a[i][j]=(s[i][j]-'0');
                b[i][j]=(s[i][j]-'0');
                if(i<n-1){
                    a[i][j]+=a[i+1][j];
                }
                if(j<n-1){
                    b[i][j]+=b[i][j+1];
                }
            }
        }
        bool bl=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='1'){
                    if((i==n-1) || (j==n-1)){
                        continue;
                    }
                    else{
                        if((s[i+1][j]=='0') && (s[i][j+1]=='0')){
                            bl=false;
                            //cout<<i<<" "<<j<<'\n';
                        }
                    }
                }
            }
        }
        if(bl){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}