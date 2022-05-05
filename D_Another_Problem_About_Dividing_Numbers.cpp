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
struct help{
    int x1,y1,i1;
};
bool f(char a,char a1,char a2 ,char a3,char a4){
    if(a=='*' && a1=='*' && a2=='*' && a3=='*' && a4=='*'){
        return true;
    }
    return false;
}
int N=40000+5;
int32_t main()
{
	FIO;
    vi prime(N,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<N;i++){
        if(prime[i]){
            for(int j=i*2;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
    vi v;
    for(int i=0;i<N;i++){
        if(prime[i]){
            v.pb(i);
        }
    }
    // cout<<v.size()<<" ";
    // for(int i=0;i<10;i++){
    //     cout<<v[i]<<" ";
    // }
    vi prefix(N,0);
    for(int i=0;i<v.size();i++){
        for(int j=v[i];j<N;j+=v[i]){
            prefix[j]++;
        }
    }
	int w=1;
	cin>>w;
	while(w--){
        int a,b,k;
        cin>>a>>b>>k;
        if(k==1){
            if((gcd(a,b)==min(a,b)) && (a!=b)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            continue;
        }
        int k1=0,k2=0;
        for(int i=0;i<v.size();i++){
            if(a%v[i]==0){
                while(a%v[i]==0){
                    k1++;
                    a/=v[i];
                }
            }
        }
        if(a>1){
            k1++;
        }
        for(int i=0;i<v.size();i++){
            if(b%v[i]==0){
                while(b%v[i]==0){
                    k2++;
                    b/=v[i];
                }
            }
        }
        if(b>1){
            k2++;
        }
        if(k1+k2>=k){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
	}
}
