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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}

int32_t main()
{
	FIO;
    int N=2*(1e5) +10;
    char x[6][N];
    x[0][0]='G',x[0][1]='R',x[0][2]='B';
    x[1][0]='G',x[1][1]='B',x[1][2]='R';
    x[2][0]='R',x[2][1]='G',x[2][2]='B';
    x[3][0]='R',x[3][1]='B',x[3][2]='G';
    x[4][0]='B',x[4][1]='R',x[4][2]='G';
    x[5][0]='B',x[5][1]='G',x[5][2]='R';
    for(int i=0;i<6;i++){
        for(int j=3;j<N;j++){
            x[i][j]=x[i][j-3];
        }
    }
    int count=inf,i1=0;
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<6;i++){
        int c1=0;
        for(int j=0;j<n;j++){
            if(x[i][j]!=a[j]){
                c1++;
            }
        }
        if(c1<count){
            count=c1;
            i1=i;
        }
    }
    cout<<count<<"\n";
    for(int i=0;i<n;i++){
        cout<<x[i1][i];
    }
    cout<<"\n";
}