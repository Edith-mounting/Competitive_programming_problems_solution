#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

int32_t main() 
{
    int w;
    cin>>w;
    while (w--)
    {
        int l,r,m;
        cin>>l>>r>>m;
        int n1,n2,n=1;
        int k;
        int one=1;
        int a=0,b=0,c=0;
        for(int i= max(one,m+l-r);i<= m+r-l;i++){
            n1=i/l;
            n2=i/r;
            k=i;
            cout<<i<<" ";
            if(n1*l==i){
                n=n1;
                a=i/n;
                if(a>=l && a<=r){
                    break;
                }
            }
            else if(n2*r==i){
                n=n2;
                a=i/n;
                if(a>=l && a<=r){
                    break;
                }
            }
            else if(n1>n2){
                n=n1;
                a=i/n;
                if(a>=l && a<=r){
                    break;
                }
            }
        }
        int q=m-k;
        if(q==0){
            b=l;
            c=l;
        }
        else if(q<0){
            b=l;
            c=l+(-q);
        }
        else{
            c=l;
            b=l+q;
        }
        cout<<a<<" "<<b<<" "<<c<<"\n";
    }
}