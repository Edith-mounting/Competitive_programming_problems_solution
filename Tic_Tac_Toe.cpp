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
struct help{
    int x,y;
};
int32_t main()
{
	FIO;
    int w;
    cin>>w;
    while(w--){
        int n,m,k;
        cin>>n>>m>>k;
        char a[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                a[i][j]='.';
            }
        }
        string s="",s1="Alice",s2="Bob",s3="Draw";
        for(int p=0;p<n*m;p++){
            int a1,b;
            cin>>a1>>b;
            if(s.length()==0){
                if(p%2==0){
                    a[a1][b]='A';
                }
                else{
                    a[a1][b]='B';
                }
                // for(int i=1;i<=n;i++){
                //     for(int j=1;j<=m;j++){
                //         cout<<a[i][j]<<" ";
                //     }
                //     cout<<"\n";
                // }
                for(int i=1;i<=n-k+1;i++){
                    for(int j=1;j<=m-k+1;j++){
                        //for each i,j we have to find if there are k*k "A" or "B";
                        int countA=0,countB=0;
                        for(int k1=i;k1<i+k;k1++){
                            for(int k2=j;k2<j+k;k2++){
                                if(a[k1][k2]=='A')countA++;
                                else if(a[k1][k2]=='B')countB++;
                            }
                        }
                        if(countA==k*k){
                            s=s1;
                        }
                        else if(countB==k*k){
                            s=s2;
                        }
                        if(s.length()!=0){
                            break;
                        }
                    }
                    if(s.length()!=0){
                        break;
                    }
                }
            }
        }
        if(s.length()==0){
            s=s3;
        }
        cout<<s<<"\n";
    }
}