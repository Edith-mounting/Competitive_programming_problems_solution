#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int32_t main(){
    int n;
    cin>>n;
    int a[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            a[i][j]=0;
        }
    }
    int x1=1,y1=1,c1=0;
    int x2=1,y2=2,c2=0;
    for(int j=0;j<n*n;j++){
        int x;
        cin>>x;
        if(x==1){
            if(c2<(n*n/2)){
                a[y2][x2]=2;
                cout<<2<<" "<<y2<<" "<<x2<<endl;
                cout<<endl;
                c2++;
                y2+=2;
                if(y2>n){
                    x2++;
                    y2=y2%n +(1-n%2);
                    if(y2==3){
                        y2-=2;
                    }
                }
            }
            else{
                a[y1][x1]=3;
                cout<<3<<" "<<y1<<" "<<x1<<endl;
                cout<<endl;
                c1++;
                y1+=2;
                if(y1>n){
                    x1++;
                    y1=y1%n +(1-n%2);
                    if(y1==3){
                        y1-=2;
                    }
                }
            }
        }
        else if(x==2){
            if(c1<(n*n/2 +n%2)){
                a[y1][x1]=1;
                cout<<1<<" "<<y1<<" "<<x1<<endl;
                cout<<endl;
                c1++;
                y1+=2;
                if(y1>n){
                    x1++;
                    y1=y1%n + (1-n%2);
                    if(y1==3){
                        y1-=2;
                    }
                }
            }
            else{
                a[y2][x2]=3;
                cout<<3<<" "<<y2<<" "<<x2<<endl;
                cout<<endl;
                c2++;
                y2+=2;
                if(y2>n){
                    x2++;
                    y2=y2%n +(1-n%2);
                    if(y2==3){
                        y2-=2;
                    }
                }
            }
        }
        else{
            if(c1<=c2){
                //col->1
                a[y1][x1]=1;
                cout<<1<<" "<<y1<<" "<<x1<<endl;
                cout<<endl;
                c1++;
                y1+=2;
                if(y1>n){
                    x1++;
                    y1=y1%n +(1-n%2);
                    if(y1==3){
                        y1-=2;
                    }
                }
            }
            else{
                //col->2
                a[y2][x2]=2;
                cout<<2<<" "<<y2<<" "<<x2<<endl;
                cout<<endl;
                c2++;
                y2+=2;
                if(y2>n){
                    x2++;
                    y2=y2%n +(1-n%2);
                    if(y2==3){
                        y2-=2;
                    }
                }
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}