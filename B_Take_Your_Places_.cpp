#include <iostream>
#include <algorithm>
#include <map>
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0)even++;
            else odd++;
        }
        if(absk(odd-even)>1){
            cout<<-1<<"\n";
            continue;
        }
        int ans=0;
        if(n%2 ==1){
            if(odd > even){
                int j=1;
                for(int i=0;i<n;i++){
                    if(a[i]%2==0 && i%2==0){
                        while(a[j]%2 ==0){
                            j+=2;
                        }
                        ans+=absk(i-j);
                        swap(a[i],a[j]);
                        j+=2;
                    }
                }
            }
            else {
                int j=1;
                for(int i=0;i<n;i++){
                    if(a[i]%2==1 && i%2==0){
                        while(a[j]%2 ==1){
                            j+=2;
                        }
                        ans+=absk(i-j);
                        swap(a[i],a[j]);
                        j+=2;
                    }
                }
            }
        }
        else{
            int temp1=0;
            int j=0;
            int b[n];
            for(int i=0;i<n;i++){
                b[i]=a[i];
            }
            for(int i=0;i<n;i++){
                if(a[i]%2==0 && i%2==1){
                    while(a[j]%2 ==0){
                        j+=2;
                    }
                    swap(a[i],a[j]);
                    temp1+=absk(i-j);
                    j+=2;
                }
            }
            ans=temp1;
            temp1=0;
            j=1;
            for(int i=0;i<n;i++){
                if(b[i]%2==0 && i%2==0){
                    while(b[j]%2 ==0){
                        j+=2;
                    }
                    swap(b[i],b[j]);
                    temp1+=absk(i-j);
                    j+=2;
                }
            }
            ans=min(ans,temp1);
        }
        cout<<ans<<"\n";
    }
}