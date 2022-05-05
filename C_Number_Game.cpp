#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
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

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        string s1="Ashishgup",s2="FastestFinger";
        if(n==1){
            cout<<s2;
        }
        else if(n==2){
            cout<<s1;
        }
        else if(n%2==1){
            cout<<s1;
        }
        else{
            int even=0,odd=0;
            while(n%2==0){
                even++;
                n/=2;
            }
            //cout<<n<<" ";
            if(n==1){
                cout<<s2;
            }
            else{
                if(even>1){
                    cout<<s1;
                }
                else{
                    int kl=n;
                    for(int i=3;i*i<=kl;i++){
                        while(n%i==0){
                            odd++;
                            n/=i;
                        }
                    }
                    if(n!=1){
                        odd++;
                    }
                    if(odd>1){
                        cout<<s1;
                    }
                    else{
                        cout<<s2;
                    }
                }
            }
        }
        cout<<"\n";
    }
}