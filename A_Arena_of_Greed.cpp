#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n;
        k=n;
        int count=0;
        if(n%2==1){
            n--;
        }
        if(n==0){
            count=0;
        }
        else if(n==1){
            count=1;
        }
        else if(n==2){
            count=1;
        }
        else if(n==3){
            count=2;
        }
        else if(n==4){
            count=3;
        }
        else{
            while(n>0){
                if(n==4){
                    count+=3;
                    break;
                }
                else{
                    if(n%4==0){
                        count+=1;
                        n-=2;
                    }
                    else if(n%2==0){
                        count+=n/2;
                        n/=2;
                        n--;
                    }
                    else{
                        count+=1;
                        n--;
                        n/=2;
                    }
                }
            }
        }
        if(k%2==0){
            cout<<count<<"\n";
        }
        else{
            cout<<k-count<<"\n";
        }
    }
}