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

#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
bool comp(pii x,pii y){
    return x.ff<y.ff;
}
int binarysearch(int l,int r,vector<pii> a,int k){
    int mid;
    while(l<=r){
        mid=l+ (r-l)/2 ;
        if(a[mid].ff==k){
            return a[mid].ss;
        }
        else if(a[mid].ff<k){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}
int32_t main(){
    FIO;
    int n,x;
    cin>>n>>x;
    map<int,int> mp;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    bool b=false;
    int x1;
    for(int i=0;i<n;i++){
        x1=x-a[i];
        if(mp.find(x1)!=mp.end()){
            if(mp[x1]!=i){
                b=true;
                cout<<i+1<<" "<<mp[x1]+1;
                break;
            }
        }
    }
    if(!b){
        cout<<"IMPOSSIBLE";
    }
    cout<<"\n";
} 