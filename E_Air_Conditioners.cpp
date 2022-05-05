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
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        int a[k];
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        vi dp(n+1,0);
        for(int i=0;i<k;i++){
            cin>>dp[a[i]];
        }
        priority_queue<pii> right,left;
        for(int i=1;i<=n;i++){
            if(dp[i]!=0){
                pii q;
                q.ff=-(dp[i]+i);
                q.ss=i;
                right.push(q);
            }
        }
        for(int i=1;i<=n;i++){
            if(dp[i]!=0){
                int mini=dp[i];
                if(!left.empty()){
                    int alpha;
                    alpha= (-left.top().ff);
                    alpha-=(n-i);
                    mini=min(mini,alpha);
                }
                while(!right.empty()){
                    pii q=right.top();
                    //cout<<-q.ff<<"\n";
                    if(q.ss<i){
                        right.pop();
                    }
                    else{
                        mini=min(mini, -q.ff -i);
                        break;
                    }
                }
                dp[i]=min(mini,dp[i]);
                pii q;
                q.ff=-(dp[i]+(n-i));
                q.ss=i;
                left.push(q);
            }
            else{
                int mini=inf;
                if(!left.empty()){
                    mini= (-left.top().ff);
                    mini-=(n-i);
                }
                while(!right.empty()){
                    pii q=right.top();
                    //cout<<-q.ff<<"\n";
                    if(q.ss<i){
                        right.pop();
                    }
                    else{
                        mini=min(mini, -q.ff -i);
                        break;
                    }
                }
                dp[i]=mini;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
    }
}