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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pos=0,ne=0;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            pos++;
        }
        else{
            ne++;
        }
    }
    if((pos%2==0 && ne%2==0)||(pos%2==1 && ne%2==1)){
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                a[i]=-a[i]-1;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                a[i]=-a[i]-1;
            }
        }
        int maxi=inf,i1;
        for(int i=0;i<n;i++){
            if(a[i]<maxi){
                maxi=a[i];
                i1=i;
            }        
        }
        a[i1]=-a[i1]-1;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}