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
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ho[n][m],vo[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ho[i][j]=0;
            vo[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((a[i][j]=='.')&&(a[i+1][j]=='.')){
                if(j==0){
                    vo[i][j]=vo[i+1][j]+1;
                }
                else{   
                    vo[i][j]=vo[i-1][j]+vo[i][j-1]-vo[i-1][j-1]+1;
                }
            }
            else{
                if(j==0){
                    vo[i][j]=vo[i-1][j];
                }
                else{
                    vo[i][j]=vo[i-1][j]+vo[i][j-1]-vo[i-1][j-1];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if((a[i][j]=='.')&&(a[i][j-1]=='.')){
                if(i==0){
                    ho[i][j]=ho[i][j-1]+1;
                }
                else{
                    ho[i][j]=ho[i-1][j]+ho[i][j-1]-ho[i-1][j-1] +1;
                }
            }
            else{
                if(i==0){
                    ho[i][j]=ho[i][j-1];
                }
                else{
                    ho[i][j]=ho[i-1][j]+ho[i][j-1]-ho[i-1][j-1];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ho[i][j]+vo[i][j]<<" ";
        }
        cout<<"\n";
    }
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--;
        int ans=0;
        ans += ho[x2-1][y2] - ho[x1][y2] - ho[x2-1][y1] + ho[x1][y1];
		ans += vo[x2][y2-1] - vo[x1][y2-1] - vo[x2][y1] + vo[x1][y1];
        cout<<ans<<"\n";
    }
}