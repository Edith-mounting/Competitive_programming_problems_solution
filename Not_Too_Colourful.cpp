#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
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
    int n,m;
    cin>>n>>m;
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int min1=min(a[0],min(a[1],a[2]));
    int min2,min3;
    char c1,c2,c3;
    if(min1==a[0]){
        c1='R';
        min2=min(a[1],a[2]);
        if(min2==a[1]){
            min3=a[2];
            c2='G';
            c3='B';
        }
        else{
            min3=a[1];
            c2='B';
            c3='G';
        }
    }
    else if(min1==a[1]){
        c1='G';
        min2=min(a[0],a[2]);
        if(min2==a[0]){
            min3=a[2];
            c2='R';
            c3='G';
        }
        else{
            min3=a[0];
            c2='G';
            c3='R';
        }
    }
    else{
        c1='B';
        min2=min(a[0],a[1]);
        if(min2==a[0]){
            min3=a[1];
            c2='R';
            c3='G';
        }
        else{
            min3=a[0];
            c2='G';
            c3='R';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i+j)%2==0){
                if(min1>0){
                    cout<<c1;
                    min1--;
                }
                else{
                    cout<<c3;
                    min3--;
                }
            }
            else{
                if(min2>0){
                    cout<<c2;
                    min2--;
                }
                else{
                    cout<<c3;
                    min3--;
                }
            }
        }
        cout<<"\n";
    }
}