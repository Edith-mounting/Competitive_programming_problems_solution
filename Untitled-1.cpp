#include <iostream>
using namespace std;
int main(){
    int k,n;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int x=0,y=1;
    if(a[x]+a[y]<=k){
        for(int i=2;i<n;i++){
            if(a[i]+a[x]+a[y]<k){
                y=i;
            }
            else if(a[i]+a[x]+a[y]=k){
                y=i;
                break;
            }
            else{
                
            }
        }
    }
    else{

    }
}