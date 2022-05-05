#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
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
    int w;
    cin>>w;
    while(w--){
        int p,q;
        cin>>p>>q;
        int x=p;
        int k1=q;
        map<int,int> m;
        for(int i=2;i*i<=q;i++){
            if(k1%i ==0){
                while(k1%i==0){
                    m[i]++;
                    k1/=i;
                }
            }
        }
        if(k1>1){
            m[k1]++;
        }
        vi v;
        for(auto i:m){
            v.pb(i.ff);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<"\n";
        for(auto i:v){
            bool b=false;
            while(x%i==0){
                if(x%q !=0){
                    b=true;
                    break;
                }
                x/=i;
            }
            if(b){
                break;
            }
        }
        cout<<x<<"\n";
    }
}
