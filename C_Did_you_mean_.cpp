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
bool check(char c){
    if((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u')){
        return true;
    }
    return false;
}
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    vi a(26,0);
    int q=0;
    for(int i=0;i<n;i++){
        if(check(s[i])){
            cout<<s[i];
        }
        else{
            if(i<=1+q){
                cout<<s[i];
                continue;
            }
            if(check(s[i-1]) || check(s[i-2])){
                cout<<s[i];
                continue;
            }
            if(s[i-1]==s[i] && s[i-2]==s[i]){
                cout<<s[i];
                continue;
            }
            // else{
            q=i;
            cout<<" "<<s[i];
            // }
        }
    }
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
	}
}
