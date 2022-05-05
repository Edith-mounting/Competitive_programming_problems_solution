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
    while(w--){
        int n;
        cin>>n;
        string s="",s1="First",s2="Second";
        int b[n];
        int a[n+1]={};
        for(int i=0;i<n;i++){
            cin>>b[i];
            a[b[i]]++;
        }
        int sum[n+1]={};
        bool bl=true;
        for(int i=1;i<n+1;i++){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<n+1;i++){
            if(a[i]>n-i+1){
                bl=false;
                break;
            }
        }
        for(int i=1;i<n+1;i++){
            if(sum[i]<i){
                bl=false;
                break;
            }
        }
        if(!bl){
            s=s2;
        }
        else{
            int sum=0,dif;
            for(int i=0;i<n;i++){
                sum+=b[i];
            }
            dif=(n*(n+1))/2-sum;
            if(dif%2==0){
                s=s2;
            }
            else{
                s=s1;
            }
        }
        cout<<s<<"\n";
    }
}