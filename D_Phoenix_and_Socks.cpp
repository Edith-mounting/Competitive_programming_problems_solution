#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
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


int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main() 
{   
    int w;
    cin>>w;
    while(w--){
        int n,l,r;
        cin>>n>>l>>r;
        vi left(l);
        int l1[n+1]={};
        for(int i=0;i<l;i++){
            cin>>left[i];
            l1[left[i]]++;
        }
        int ans=0;
        vi right(r);
        int r1[n+1]={};
        for(int i=l;i<n;i++){
            cin>>right[i-l];
            if(l1[right[i-l]]>0){
                l1[right[i-l]]--;
            }
            else{
                r1[right[i-l]]++;
            }
        }
        int x1=0,x2=0;
        for(int i=1;i<=n;i++){
            x1+=l1[i];
        }
        for(int i=1;i<=n;i++){
            x2+=r1[i];
        }
        /*for(int i=1;i<=n;i++){
            cout<<l1[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=n;i++){
            cout<<r1[i]<<" ";
        }
        cout<<"\n";*/
        if(x1==x2){
            ans=x1;
            x1=0,x2=0;
        }
        else if(x1>x2){
            for(int i=1;i<=n;i++){
                if(l1[i]>1){
                    int q=l1[i]-l1[i]%2;
                    if((x1-x2)>=(q)){
                        l1[i]=l1[i]%2;
                        ans+=(q/2);
                        x1=x1-q;
                    }
                    else{
                        ans+=(x1-x2)/2;
                        l1[i]=l1[i]-(x1-x2);
                        x1=x2;
                    }
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(r1[i]>1){
                    int q=r1[i]-r1[i]%2;
                    if((x2-x1)>=(q)){
                        r1[i]=r1[i]%2;
                        ans+=(q/2);
                        x2=x2-q;
                    }
                    else{
                        ans+=(x2-x1)/2;
                        r1[i]=r1[i]-(x2-x1);
                        x2=x1;
                    }
                }
            }
        }
        ans+=max(x1,x2);
        cout<<ans<<"\n";
    }
}