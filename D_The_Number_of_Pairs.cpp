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
int N=20000000+5;
vi prime;
void primex(){
    prime.resize(N,0);
    for(int i=2;i<N;i++){
	    if(prime[i]==0){
	    	for(int j=i;j<N;j+=i) prime[j]++;
	    }
    }
}
int f(int i,int c,int d,int x){
    int ans=0;
    int k1=((i+d)/c);
    if(((k1*c)-d)==i){
        if(x%i==0){
            int k2=k1;
            if(k2==1){
                ans++;
            }
            else{
                ans+=(int)1 <<prime[k2];
            }
        }
    }
    return ans;
}
int32_t main() 
{
    primex();
    int w;
    cin>>w;
    while(w--){
        int c,d,x;
        cin>>c>>d>>x;
        int cl=__gcd(c,__gcd(d,x));
        c/=cl;
        d/=cl;
        x/=cl;
        int count=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int k3=x/i;
                if(k3==i){
                    count+=f(i,c,d,x);
                }
                else{
                    count+=f(i,c,d,x);
                    count+=f(k3,c,d,x);
                }
            }
        }
        cout<<count<<"\n";
    }
}