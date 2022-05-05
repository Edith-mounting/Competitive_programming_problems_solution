#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n/2;i++){
        swap(a[i],a[n-i-1]);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}