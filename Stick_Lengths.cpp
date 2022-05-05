#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool> 
#define inf             1e18  
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int             long long
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int32_t main(){
    FIO;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans;
    if(n%2==0){
        int k1=a[n/2],k2=a[n/2 -1];
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(k1>a[i]){
                count1+=(k1-a[i]);
            }
            else{
                count1+=(a[i]-k1);
            }
            if(k2>a[i]){
                count2+=(k2-a[i]);
            }
            else{
                count2+=(a[i]-k2);
            }
        }
        ans=min(count1,count2);
    }
    else{
        int k1=a[(n-1)/2];
        int count1=0;
        for(int i=0;i<n;i++){
            if(k1>a[i]){
                count1+=(k1-a[i]);
            }
            else{
                count1+=(a[i]-k1);
            }
        }
        ans=count1;
    }
    cout<<ans;
    cout<<"\n";
} 