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
void swap(int &x,int &y){
    int k=x;
    x=y;
    y=k;
}
int32_t main() {
    int wk;
    cin>>wk;
    while(wk--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int c=n-1;
        map<pii,bool> mp;
        for(int i=0;i<n;i++){
            if(c==0){
                break;
            }
            int index;
            for(int j=0;j<n;j++){
                if(a[j]==i+1){
                    index=j;
                    break;
                }
            }
            if(index==i){
                continue;
            }
            else{
                for(int j=index;j>=i+1;j--){
                    if(c!=0){
                        if(a[j]<a[j-1]){
                        if(mp.find({j,j-1})==mp.end()){
                            swap(a[j],a[j-1]);
                            c--;
                            mp[{j,j-1}]=true;
                        }
                        else{
                            break;
                        }}
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}