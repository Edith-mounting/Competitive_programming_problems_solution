#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
 
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
int32_t main(){
    FIO;
    vector<vi> a(5,vector<int>(5,0));
    string s;
    cin>>s;
    int n=s.length();
    for(int k=0;k<n;k++){
        if(s[k]=='1'){
            if(a[1][1]==1){
                cout<<1<<" "<<3<<"\n";
                a[1][3]=1,a[1][4]=1;
            }
            else{
                cout<<1<<" "<<1<<"\n";
                a[1][1]=1,a[1][2]=1;
            }
        }
        else{
            for(int j=1;j<5;j++){
                if(a[3][j]==0 && a[4][j]==0){
                    a[3][j]=1;
                    a[4][j]=1;
                    cout<<3<<" "<<j<<"\n";
                    break;
                }
            }
        }
        // for(int i=1;i<5;i++){
        //     if(a[1][i]==1 && a[2][i]==1 && a[3][i]==1 && a[4][i]==1){
        //         a[1][i]=0,a[2][i]=0,a[3][i]=0,a[4][i]=0;
        //     }
        // }
        for(int i=1;i<5;i++){
            if(a[i][1]==1 && a[i][2]==1 && a[i][3]==1 && a[i][4]==1){
                a[i][1]=0,a[i][2]=0,a[i][3]=0,a[i][4]=0;
            }
        }
        // for(int p=1;p<5;p++){
        //     for(int q=1;q<5;q++){
        //         cout<<a[p][q]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
    }
}