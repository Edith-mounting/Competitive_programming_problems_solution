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
#define mod             1000000007
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
    vi in(n+1,0);
    vi out(n+1,0);
    for(int i=0;i<n;i++){
        out[i+1]=a[i];
        in[a[i]]=i+1;
    }
    int count=0;
    for(int i=1;i<n+1;i++){
        if(out[i]==0){
            count++;
        }
    }
    if(count==0){
        int i1=-1;
        //cout<<"YES";
        for(int i=1;i<n+1;i++){
            if(out[i]==0){
                if(i1==-1){
                    i1=i;
                }
                else{
                    out[i]=i1;
                    out[i1]=i;
                }
            }
        }
    }
    else{
        int i1;
        for(int i=1;i<n+1;i++){
            if(out[i]==0){
                i1=i;break;
            }
        }
        int i2;
        for(int i=i1+1;i<n+1;i++){
            if(in[i]==0){
                i2=i;
                break;
            }
        }
        //cout<<i1<<" "<<i2<<"\n";
        int i;
        for(i=i1;i<n+1;i++){
            if(out[i]==0){
                bool bl=true;
                for(int j=i2;j<n+1;j++){
                    if(in[j]==0 && (j!=i)){
                        out[i]=j;
                        in[j]=i;
                        i2=j;
                        bl=false;
                        break;
                    }
                }
                if(bl){
                    break;
                }
            }
        }
        i2=1;
        for(int j=i;j<n+1;j++){
            if(out[j]==0){
                for(int k=i2;k<n+1;k++){
                    if(in[k]==0 && k!=j){
                        out[j]=k;
                        in[k]=j;
                        i2=k;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<out[i]<<" ";
    }
    cout<<"\n";
}