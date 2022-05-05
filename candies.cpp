#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=1;
    int m=1;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            x=x+m;
            m++;
        }
        else if(a[i]==a[i+1]){
            x++;
            m=0;
        }
        else{x=x+1;
        m=0;}
    }
}