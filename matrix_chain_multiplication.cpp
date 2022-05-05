#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <map> 
#include <iomanip>
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
const double pi = acos(-1);
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=inf;
        }
    }
    for(int i=0;i<n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int j=l;j<n;j++){
            int i=(j-l+1);
            for(int k=i;k<j;k++){
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
    }
    cout<<m[1][n-1]<<"\n";
}