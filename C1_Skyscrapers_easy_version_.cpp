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
    vi ans(n,0);
    int maxi=0;
    vi temp(n,0);
    int temp_maxi=0;
    temp[0]=a[0];
    temp_maxi=a[0];
    for(int i=1;i<n;i++){
        temp[i]=min(a[i],temp[i-1]);
        temp_maxi+=temp[i];
    }

    if(temp_maxi>maxi){
        for(int i=0;i<n;i++){
            ans[i]=temp[i];
        }
        maxi=temp_maxi;
    }
    temp_maxi=0;
    temp.clear();
    temp[n-1]=a[n-1];
    temp_maxi+=a[n-1];
    for(int i=n-2;i>=0;i--){
        temp[i]=min(a[i],temp[i+1]);
        temp_maxi+=temp[i];
    }
    if(temp_maxi>maxi){
        for(int i=0;i<n;i++){
            ans[i]=temp[i];
        }
        maxi=temp_maxi;
    }
    for(int i=1;i<n-1;i++){
        temp_maxi=0;
        temp.clear();
        temp[i]=a[i];
        temp_maxi+=a[i];
        for(int j=i-1;j>=0;j--){
            temp[j]=min(a[j],temp[j+1]);
            temp_maxi+=temp[j];
        }
        for(int j=i+1;j<n;j++){
            temp[j]=min(a[j],temp[j-1]);
            temp_maxi+=temp[j];
        }
        if(temp_maxi>maxi){
            for(int i=0;i<n;i++){
                ans[i]=temp[i];
            }
            maxi=temp_maxi;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}