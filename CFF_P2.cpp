#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*bool comparator(pair<int,string> a , pair<int,string> b){
    return a.first < b.first ;
}*/

int isSubsetSum(int set[], int n, int sum,int k,bool subset[][8000+1])
{
    cout<<sum<<"\n";
    int ans=0;
    vector<bool> v(n,true);
    int kl=sum;
    while(kl>0){
        for(int i=0;i<n;i++){
            if(v[i]){
                if(kl-set[i]>=0){
                    if(subset[(n)%2][kl-set[i]]){
                        kl=kl-set[i];
                        cout<<set[i]<<" ";
                        v[i]=false;
                        ans++;
                    }
                }
            }
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        if(v[i]){
            if(k>set[i]){
                ans++;
                k-=set[i];
            }
            else{
                ans++;
                k=0;
                break;
            }
        }
    }
    if(k!=0){
        return -1;
    }
    else{
        return ans;
    }
}
int solve(){
    int n,k;
    cin>>n>>k;
    //n=rand()%5 +1;
    //k=rand()%15 +1;
    //n=4000;
    //k=4000;
    int a[n];
    bool b=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //a[i]=rand()%10 +1;
        //a[i]=3999;
        if(a[i]>=k){
            b=false;
        }
    }
    /*cout<<n<<" "<<k<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";*/
    if(n==1){
        return -1;
    }
    int ans=0;
    sort(a,a+n,greater<int>());
    if(!b){
        ans++;
        int sum1=0;
        for(int i=1;i<n;i++){
            if(sum1<k){
                sum1+=a[i];
                ans++;
            }
            else{
                break;
            }
        }
        if(sum1<k){
            return -1;
        }
        else{
            return ans;
        }
    }
    else{
        int klm=0;
        for(int i=0;i<n;i++){
            klm+=a[i];
        }
        if(klm<2*k){
            return -1;
        }
        bool subset[2][8000 + 1]; 
  
        for (int i = 0; i <= n; i++) { 
            for (int j = 0; j <= 8000; j++) { 
    
                // A subset with sum 0 is always possible  
                if (j == 0) 
                    subset[i % 2][j] = true;  
    
                // If there exists no element no sum  
                // is possible  
                else if (i == 0) 
                    subset[i % 2][j] = false;  
                else if (a[i - 1] <= j) 
                    subset[i % 2][j] = subset[(i + 1) % 2] 
                [j - a[i - 1]] || subset[(i + 1) % 2][j]; 
                else
                    subset[i % 2][j] = subset[(i + 1) % 2][j]; 
            } 
        } 
  
        //int ans=0;
        int sum=k;
        while(1){
            if(subset[n%2][sum]){
                return isSubsetSum(a,n,sum,k,subset);
            }
            else{
                sum++;
                //isSubsetSum(a,n,sum,k);
            }
        }
    }
}
int32_t main() 
{   
    int w;
    cin>>w;
    while(w--){
        cout<<solve();
        cout<<"\n";
    }
}

