#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <queue> 
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

struct s1{
    int up,left;
};
struct s2{
    int down,right;
};
int32_t main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='*'){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
    }
    s1 m1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                m1[i][j].up=a[i][j];
            }
            else{
                m1[i][j].up=m1[i-1][j].up+a[i][j];
            }
            if(j==0){
                m1[i][j].left=a[i][j];
            }
            else{
                m1[i][j].left=m1[i][j-1].left+a[i][j];
            }
        }
    }
    s2 m2[n][m];
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1){
                m2[i][j].down=a[i][j];
            }
            else{
                m2[i][j].down=m2[i+1][j].down+a[i][j];
            }
            if(j==m-1){
                m2[i][j].right=a[i][j];
            }
            else{
                m2[i][j].right=m2[i][j+1].right+a[i][j];
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                ans+=(m1[i][j].up-1)*(m1[i][j].left-1);
                ans+=(m1[i][j].left-1)*(m2[i][j].down-1);
                ans+=(m2[i][j].down -1)*(m2[i][j].right -1);
                ans+=(m2[i][j].right -1)*(m1[i][j].up -1);
            }
        }
    }
    cout<<ans<<"\n";
}