#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void solve(){
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=0,y=0;
    bool bl=true;
    for(int i=0;i<n;i++){
        if(a[i]==25){
            x++;
        }
        else if(a[i]==50){
            if(x>=1){
                x-=1;
                y++;
            }
            else{
                bl=false;
                break;
            }
        }
        else{
            if(y>=1){
                y--;
                if(x>=1){
                    x--;
                }
                else{
                    bl=false;
                }
            }
            else{
                if(x>=3){
                    x-=3;
                }
                else{
                    bl=false;
                }
            }
        }
    }
    if(bl){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
		cout<<"\n";
	}

}
