#include <iostream>
#include <algorithm>
#include <map>
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
    int w=1;
    while (w--)
    {
        /* code */
        int x,y;
        cin>>x>>y;
        string s1="white",s2="black";
        string s;
        int r;
        if(x==0 || y==0){
            cout<<s2;
            continue;
        }
        bool bl=false;
        int q=sqrt(x*x + y*y); 
        if(q*q==x*x+y*y){
            s=s2;
            cout<<s;
            continue;
        }
        for(r=0;r<10005;){
            int l1=x*x+y*y-r*r;
            if(l1<0){
                break;
            }
            r++;
        }
        if(bl){
            continue;
        }
        if((x<0 && y>0) || (x>0 && y<0)){
            if(r%2==0){
                s=s2;
            }
            else{
                s=s1;
            }
        }
        else{
            if(r%2==0){
                s=s1;
            }
            else{
                s=s2;
            }
        }
        cout<<s<<"\n";
    }  
}