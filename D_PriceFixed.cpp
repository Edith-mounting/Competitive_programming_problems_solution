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
    int n;
    cin>>n;
    int count=0,cost=0;
    multiset<pii> s;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        s.insert({b,a});
    }
    while(!s.empty()){
        if(s.size()==1){
            int a1,b1;
            auto itr1=s.begin();
            a1=(*itr1).ss,b1=(*itr1).ff;
            if(count>=b1){
                cost+=a1;
            }
            else if(count+a1>b1){
                int k=(b1-count);
                cost+=2*k+(a1-k);
            }
            else{
                cost+=2*a1;
            }
            break;
        }
        auto itr1=s.begin();
        auto itr2=s.end();
        itr2--;
        int a1,a2,b1,b2;
        a1=(*itr1).ss,b1=(*itr1).ff;
        a2=(*itr2).ss,b2=(*itr2).ff;
        if(count>=b1){
            cost+=a1;
            count+=a1;
            s.erase(s.find(*itr1));
        }
        else if(count+a2>=b1){
            int k=b1-count;
            a2=a2-k;
            count+=a1+k;
            cost+=2*(k)+a1;
            s.erase(s.find(*itr1));
            s.erase(s.find(*itr2));
            s.insert({b2,a2});
        }
        else{
            count+=a2;
            cost+=2*a2;
            s.erase(s.find({b2,a2}));
        }
    }
    cout<<cost<<"\n";
}