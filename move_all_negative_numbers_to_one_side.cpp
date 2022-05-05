#include <iostream>
using namespace std;

void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            if(i==j){
                continue;
            }
            else if(a[j]>0){
                swap(a[j],a[i]);
                j++;
            }
            else{
                while(a[j]<0 && j<i){
                    j++;
                }
                // cout<<j<<" ";
                if(i==j){
                    continue;
                }
                else{
                    swap(a[j],a[i]);
                    j++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}