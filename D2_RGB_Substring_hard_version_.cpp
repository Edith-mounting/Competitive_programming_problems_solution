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
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             998244353
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
    int w;
    cin>>w;
    int N=1000000;
    char a[N];
    for(int i=0;i<N;i++){
        if(i%3==0){
            a[i]='R';
        }
        else if(i%3==1){
            a[i]='G';
        }
        else{
            a[i]='B';
        }
    }
    while(w--){
        int n,k;
        cin>>n>>k;
        char s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int i1=0,i2=k;
        int ans=inf;
        int count1=0,count2=0,count3=0;
        for(int i=0;i<k;i++){
            if(s[i]!=a[i]){
                count1++;
            }  
            if(s[i]!=a[i+1]){
                count2++;
            }
            if(s[i]!=a[i+2]){
                count3++;
            }
        }
        ans=min(count1,min(count2,count3));
        for(int i=k;i<n;i++){
            if(s[i]==a[i]){
                if(s[i-k]!=a[i-k]){
                    count1--;
                }
            }
            else{
                if(s[i-k]==a[i-k]){
                    count1++;
                }
            }
            if(s[i]==a[i+1]){
                if(s[i-k]!=a[i-k+1]){
                    count2--;
                }
            }
            else{
                if(s[i-k]==a[i-k+1]){
                    count2++;
                }
            }
            if(s[i]==a[i+2]){
                if(s[i-k]!=a[i-k+2]){
                    count3--;
                }
            }
            else{
                if(s[i-k]==a[i-k+2]){
                    count3++;
                }
            }
            ans=min(ans,min(count1,min(count2,count3)));
        }
        cout<<ans<<"\n";
    }
}