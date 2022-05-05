#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,q;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>q;
        if(a[0]==1){
            while(q--){
                int r;
                cin>>r;
                if(r%n==0){
                    cout<<(r/n)%mod ;
                }
                else{
                    cout<<((r/n)%mod +1)%mod;
                }
                cout<<"\n";
            }
        }
        else if(a[n-1]==1){
            int sumarray[n];
            sumarray[0]=a[0] - a[0]%2;
            for(int i=1;i<n-1;i++){
                sumarray[i]=(sumarray[i-1] +a[i] - a[i]%2) ;
            }
            sumarray[n-1]=sumarray[n-2]+1;
            while(q--){
                int r;
                cin>>r;
                int pl=(((sumarray[n-1])%mod)*(r/n)%mod)%mod;
                if(r%n!=0){
                    int ml=r%n -1;
                    if(a[ml]%2==0){
                        pl=(pl%mod +sumarray[ml]%mod)%mod;
                    }
                    else{
                        pl=(pl%mod+ sumarray[ml]%mod +1%mod)%mod;
                    }
                }
                cout<<pl<<"\n";
            }
        }
        else{
            int k=inf;
            for(int i=0;i<n;i++){
                if(a[i]==1){
                    k=i;
                    break;
                }
            }
            if(k==inf){
                int sumarray[n];
                sumarray[0]=a[0] - a[0]%2;
                for(int i=1;i<n-1;i++){
                    sumarray[i]=(sumarray[i-1] +a[i] - a[i]%2) ;
                }
                while(q--){
                    int r;
                    cin>>r;
                    int pl=(((sumarray[n-1])%mod)*((r/n)%mod))%mod;
                    if(r%n!=0){
                        int ml=r%n -1;
                        if(a[ml]%2==0){
                            pl=(pl%mod +sumarray[ml]%mod)%mod;
                        }
                        else{
                            pl=(pl%mod+ sumarray[ml]%mod +1%mod)%mod;
                        }
                    }
                    cout<<pl<<"\n";
                }
            }
            else{
                int sumarray[n];
                for(int i=0;i<n;i++){
                    if(i==k-1){
                        if(i==0){
                            sumarray[i]=a[i]-1+ a[i]%2 ;
                        }
                        else{
                            sumarray[i] =sumarray[i-1]+a[i]-1 +a[i]%2;
                        }
                    }
                    else if(i==k){
                        sumarray[i]=sumarray[i-1];
                    }
                    else{
                        if(i==0){
                            sumarray[i]=a[i]-a[i]%2;
                        }
                        else{
                            sumarray[i]=sumarray[i-1]+a[i]-a[i]%2;
                        }
                    }
                }
                while(q--){
                    int r;
                    cin>>r;
                    int pl=((sumarray[n-1]%mod)*(r/n)%mod)%mod;
                    if(r%n!=0){
                        int ml=r%n-1;
                        if(ml==k-1){
                            pl=(pl%mod +sumarray[k-1]%mod +(1-a[k-1]%2)%mod)%mod;
                        }
                        else if(ml==k){
                            int x;
                            if(a[k-1]%2==0){
                                x=2;
                            }
                            else{
                                x=0;
                            }
                            pl=(pl%mod + sumarray[k]%mod +x%mod)%mod;
                        }
                        else{
                            pl=(pl+ sumarray[ml]%mod +a[ml]%2)%mod ;
                        }
                    }
                    cout<<pl<<"\n";
                }

            }
        }
    }
}