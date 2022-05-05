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
        vector<int> v(10,0);
        char a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            v[a[i]-'0']++;
        }
        if(v[1]>0 || v[4]>0 || v[6]>0 || v[8]>0 || v[9]>0){
            cout<<1<<"\n";
            if(v[1]>0){
                cout<<1<<"\n";
            }
            else if(v[4]>0){
                cout<<4<<"\n";
            }
            else if(v[6]>0){
                cout<<6<<"\n";
            }
            else if(v[8]>0){
                cout<<8<<"\n";
            }
            else{
                cout<<9<<"\n";
            }
        }
        else{
            if(v[2]>1 || v[3]>1 || v[5]>1 || v[7]>1){
                cout<<2<<"\n";
                if(v[2]>1){
                    cout<<22<<"\n";
                }
                else if(v[3]>1){
                    cout<<33<<"\n";
                }
                else if(v[5]>1){
                    cout<<55<<"\n";
                }
                else{
                    cout<<77<<"\n";
                }
            }
            else{
                if(n==4){
                    cout<<2<<"\n";
                    if(a[0]=='2'){
                        cout<<27<<"\n";
                    }
                    else{
                        for(int i=0;i<n;i++){
                            if(a[i]=='2'){
                                cout<<a[i-1]<<a[i]<<"\n";
                                break;
                            }
                        }
                    }
                }
                else if(n==3){
                    cout<<2<<"\n";
                    if(v[2]==0){
                        if(a[0]=='3'){
                            cout<<35<<"\n";
                        }
                        if(a[0]=='5'){
                            cout<<57<<"\n";
                        }
                        if(a[0]=='7'){
                            cout<<75<<"\n";
                        }
                    }
                    else if(v[3]==0){
                        if(a[0]=='2'){
                            cout<<25<<"\n";
                        }
                        if(a[0]=='5'){
                            cout<<52<<"\n";
                        }
                        if(a[0]=='7'){
                            cout<<75<<"\n";
                        }
                    }
                    else if(v[5]==0){
                        if(a[0]=='2'){
                            cout<<27<<"\n";
                        }
                        if(a[0]=='3'){
                            cout<<32<<"\n";
                        }
                        if(a[0]=='7'){
                            cout<<72<<"\n";
                        }
                    }
                    else{
                        if(a[0]=='2'){
                            cout<<25<<"\n";
                        }
                        if(a[0]=='3'){
                            cout<<32<<"\n";
                        }
                        if(a[0]=='5'){
                            cout<<52<<"\n";
                        }
                    }
                }
                else{
                    cout<<n<<"\n";
                    for(int i=0;i<n;i++){
                        cout<<a[i];
                    }
                    cout<<"\n";
                }
            }
        }
    }
}