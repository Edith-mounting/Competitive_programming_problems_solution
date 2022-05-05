#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,c=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i%2==0){
            c+=a[i+1]-a[i];
        }
    }
    cout<<c;
}