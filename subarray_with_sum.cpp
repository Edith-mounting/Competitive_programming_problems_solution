#include<iostream>
#include <algorithm>
#include <vector>
#include <map>
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
vector<int> subarraySum(int a[], int n, int s){
    // Your code here
    int start_index,current_sum;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]<=s){
            start_index=i;
            current_sum=a[i];
            break;
        }
    }
    if(current_sum==s){
        v.push_back(start_index+1);
        v.push_back(start_index+1);
        return v;
    }
    for(int i=start_index+1;i<n;){
        current_sum=current_sum+a[i];
        if(current_sum<s){
            i++;
            continue;
        }
        else if(current_sum==s){
            v.push_back(start_index+1);
            v.push_back(i+1);
            return v;
        }
        else{
            while(current_sum>s){
                if(start_index<i){
                    current_sum=current_sum-a[start_index];
                    start_index++;    
                }
                else{
                    current_sum=a[i];
                    start_index=i;
                    i++;
                }
            }
        }
    }
    v.push_back(-1);
    return v;    
}
int32_t main(){
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v1=subarraySum(a,n,s);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}