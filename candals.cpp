#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++){
        a[i]=0;
    }
    int k;
    for(int i=0;i<m;i++){
        a[i]=n/m;
    }
    k=n%m;
    for(int i=0;i<k;i++){
        a[i]++;
    }
    for(int i=m-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
}