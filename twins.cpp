#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],c=0,l=0,p=0,x=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c+=a[i];
    }
    p=(c/2);
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        if(l>p)break;
        else{
            l+=a[i];
            x++;
        }
    }
    cout<<x;
}