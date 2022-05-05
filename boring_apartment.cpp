#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        if(s.size()==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int k=a[0],k1;
            for(int i=1;i<n;i++){
                if(a[i]!=k){
                    k1=i;
                    cout<<1<<" "<<i+1<<"\n";
                }
            }
            for(int i=1;i<n;i++){
                if(a[i]==a[0]){
                    cout<<k1+1<<" "<<i+1<<"\n";
                }
            }
        }
    }
}