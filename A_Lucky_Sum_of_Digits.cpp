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
    vi v(n+1,-1);
    v[0]=0;
    if(n>=4){
        v[4]=0;
    }
    if(n>=7){
        v[7]=0;
    }
    for(int i=8;i<n+1;i++){
        if(v[i-7]!=-1){
            v[i]=i-7;
        }
        else if(v[i-4]!=-1){
            v[i]=i-4;
        }
        else{
            v[i]=-1;
        }
    }
    int a4=0,a7=0;
    if(v[n]==-1){
        cout<<-1;
    }
    else{
        while(n!=0){
            if(n-v[n]==4){
                a4++;
            }
            else{
                a7++;
            }
            n=v[n];
        }
        for(int i=0;i<a4;i++){
            cout<<4;
        }
        for(int i=0;i<a7;i++){
            cout<<7;
        }
    }
    cout<<"\n";
}