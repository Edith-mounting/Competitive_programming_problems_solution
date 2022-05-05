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
        int n,m;
        cin>>n>>m;
        bool b=true;
        if(n>m){
            swap(n,m);
            b=false;
        }
        char a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]='a';
            }
        }
        int c=(n*m/2) +1;
        if((n*m)%2==0){
            c=(n*m)/2;
            c-=1;
        }
        int x=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==0){
                    if(j%2==0){
                        a[i][j]='B';
                    }
                    else{
                        if(x<=c){
                            x++;
                            a[i][j]='W';
                        }
                        else{
                            a[i][j]='B';
                        }
                    }
                }
                else{
                    if(j%2==0){
                        if(x<=c){
                            x++;
                            a[i][j]='W';
                        }
                        else{
                            a[i][j]='B';
                        }
                    }
                    else{
                        a[i][j]='B';
                    }
                }
            }
        }
        if(b){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<a[i][j];
                }
                cout<<"\n";
            }
        }
        else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cout<<a[j][i];
                }
                cout<<"\n";
            }
        }
    }        
}