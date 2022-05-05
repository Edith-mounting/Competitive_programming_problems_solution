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
int sq(int k){
    return (k*k)%mod;
}
bool cmp(string s1,string s2){
    int x1=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='b')x1++;
    }
    int x2=0;
    for(int i=0;i<s2.length();i++){
        if(s2[i]=='b')x2++;
    }
    if(x1==s1.length()){
        return s2<s1;
    }
    else if(x2==s2.length()){
        return s1<s2;
    }
    else if(x1==x2){
        return s2.length()<s1.length();
    }
    else{
        return x1<x2;
    }
}
int32_t main() 
{
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    int k=0,ans=0;
    /*for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }*/
    for(int i=n-1;i>=0;i--){
        int x1=0,x2=0;
        for(int j=a[i].length()-1;j>=0;j--){
            if(a[i][j]=='a'){
                ans+=x2;
                x1++;
            }
            else{
                x2++;
            }
        }
        ans+=k*x1;
        k=k+x2;
    }
    cout<<ans<<"\n";
}