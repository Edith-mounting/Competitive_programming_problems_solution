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
    int w,wl;
    cin>>w;
    wl=w;
    while(w--){
        cout<<"Case #"<<wl-w<<": ";
        int n,c;
        cin>>n>>c;
        int a[n]={};
        if(c<n-1){
            cout<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        if(c>=(n*(n+1))/2){
            cout<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        c=c-n+1;
        if(c==(n*(n-1))/2){
            int i1=n-1,i2=0;
            int x=1;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    a[i1]=x;
                    i1--;
                }
                else{
                    a[i2]=x;
                    i2++;
                }
                x++;
            }
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
            continue;
        }
        int sum=n-1,count=0;
        while(1){
            if(c<sum){
                int i1=n-1,i2=0;
                int x=1;
                for(int i=0;i<count;i++){
                    if(i%2==0){
                        a[i1]=x;
                        x++;
                        i1--;
                    }
                    else{
                        a[i2]=x;
                        x++;
                        i2++;
                    }
                }
                if(count%2==1){
                    int y=n;
                    for(int i=i2;i<i2+sum-c;i++){
                        a[i]=y;
                        y--;
                    }
                    for(int i=i1;i>=(i2+sum-c);i--){
                        a[i]=y;
                        y--;
                    }
                }
                else{
                    for(int i=i2;i<i2+sum-c;i++){
                        a[i]=x;
                        x++;
                    }
                    for(int i=i1;i>=(i2+sum-c);i--){
                        a[i]=x;
                        x++;
                    }
                }
                break;
            }
            count++;
            sum+=n-1-count;
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}