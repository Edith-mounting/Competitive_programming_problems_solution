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
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
int32_t main(){
    FIO;
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    vi a(26,0);
    vi b(26,0);
    for(int i=0;i<n;i++){
        a[s1[i]-'a']++;
    }
    for(int i=0;i<m;i++){
        b[s2[i]-'a']++;
    }
    int x=0;
    for(int i=0;i<26;i++){
        if(b[i]!=0 && a[i]==0){
            x=-1;
            break;
        }
    }
    if(x==0){
        for(int i=0;i<m;){
            int j=i;
            x++;
            for(int k=0;k<n;k++){
                if(j>=m){
                    break;
                }
                if(s1[k]==s2[j]){
                    j++;
                }
            }
            i=j-1;
            i++;
        }
    }
    cout<<x<<"\n";
}