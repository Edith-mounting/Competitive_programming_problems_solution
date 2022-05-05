#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k;
    cin>>k;
    while(k--){
        int h;
        cin>>h;
        if(h >= a[n-1]){
            cout<<0<<"\n";
        }
        else{
            int upper = upper_bound(a,a+n,h) - a;
            cout<<(n-upper)<<"\n";
        }
    }
}