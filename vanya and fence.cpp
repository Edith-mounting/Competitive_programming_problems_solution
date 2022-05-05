#include <iostream>
using namespace std;
int main(){
    int n,h,k=0;
    cin>>n>>h;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]>h)k+=2;
        else k++;
    }
    cout<<k;
}
