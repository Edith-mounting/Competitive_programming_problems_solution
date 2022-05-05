#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int32_t main(){
    int n;
    cin>>n;
    int ans;
    for(int i=1;i<11;i++){
        if(n%i==0){
            ans=i;
        }
    }
    cout<<ans<<"\n";
}