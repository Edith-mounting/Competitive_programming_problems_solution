#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

int32_t main() 
{
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        string a;
        cin>>a;
        int count1=0,count0=0,countl=0;
        for(int i=0;i<k;i++){
            if(a[i]=='1')count1++;
            else if(a[i]=='0')count0++;
            else{
                countl++;
            }
        }
        bool b=true;
        if(count1<count0){
            if(count1+countl<count0){
                b=false;
            }
        }
        else{
            if(count0+countl<count1){
                b=false;
            }
        }
        if(b){
            for(int i=k;i<n;i++){
                if(a[i]=='?'){
                    a[i]=a[i-k];
                }
                else if(a[i-k]=='?'){
                    a[i-k+1]=a[i];
                }
                else if(a[i]!=a[i-k]){
                    b=false;
                    break;
                }
            }
            if(!b){
                cout<<"NO";
            }
            else{
                cout<<"YES";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}