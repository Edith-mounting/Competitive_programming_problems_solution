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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int q;
    cin>>q;
    vi ans(n,-1);
    int kl[q][3];
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        if(k==1){
            int p,x;
            cin>>p>>x;
            kl[i][0]=1;
            kl[i][1]=p;
            kl[i][2]=x;
        }
        else{
            int x;
            cin>>x;
            kl[i][0]=2;
            kl[i][1]=x;
        }
    }
    vi maxi(q,0);
    if(kl[q-1][0]==2){
        maxi[q-1]=kl[q-1][1];
    }
    for(int i=q-2;i>=0;i--){
        if(kl[i][0]==2){
            maxi[i]=max(maxi[i+1],kl[i][1]);
        }
        else{
            maxi[i]=maxi[i+1];
        }
    }
    for(int i=q-1;i>=0;i--){
        if(kl[i][0]==1){
            int p=kl[i][1];
            p--;
            if(ans[p]==-1){
                ans[p]=max(maxi[i],kl[i][2]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]==-1){
            ans[i]=max(a[i],maxi[0]);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}